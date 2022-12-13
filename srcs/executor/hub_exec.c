/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:12:10 by lfantine          #+#    #+#             */
/*   Updated: 2022/12/13 20:05:17 by tsorabel         ###   ########.fr       */
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
	t_chain	chain;

	if (dta->prompt == NULL)
		return (0);
	if (pipe(chain.fd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	if (make_allcmd(&chain, dta) == -1)
		return (-1);
	if (change_command(&chain, 0, 0, 0) == -1)
	{
		free_allcmd(&chain);
		return (-1);
	}
	make_chains(&chain, dta);
	free_allcmd(&chain);
	return (0);
}
