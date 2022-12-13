/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:12:10 by lfantine          #+#    #+#             */
/*   Updated: 2022/12/13 10:40:06 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_char_tab(char **line, char c)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][j] == c)
				return (i + 1);
			j++;
		}
		i++;
	}
	return (-1);
}

int	take_file(t_chain *chain, char **line)
{
	int	i;

	i = is_char_tab(line, '<');
	if (i > -1)
	{
		chain->infile = line[i];
		if (access(chain->infile, R_OK) == -1)
		{
			perror(chain->infile);
			return (-1);
		}
	}
	i = is_char_tab(line, '>');
	if (i > -1)
		chain->outfile = line[i];
	return (0);
}

void	print_tab(t_cmd *cmd)
{
	int	i;
	
	i = 0;
	while (cmd->cmd[i])
	{
		printf("%s\n", cmd->cmd[i]);
		i++;
	}
	printf("----------\n");
}

int	hub_exec(t_data *dta)
{
	int		i;
	t_chain	chain;

	i = 0;
	chain.infile = NULL;
	chain.outfile = NULL;
	if (dta->prompt == NULL)
		return (0);
	if (take_file(&chain, dta->prompt) == -1)
		return (-1);
	if (pipe(chain.fd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	if (make_allcmd(&chain, dta) == -1)
		return (-1);
	int	k = 0;
	while (chain.allcmd[k])
	{
		printf("element %d\n", k);
		print_tab(chain.allcmd[k]);
		k++;
	}
	// make_chains(&chain, dta);
	free_allcmd(&chain);
	free_tab(dta->env);
	dta->exit = 1;
	return (0);
}