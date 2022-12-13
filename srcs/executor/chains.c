/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:08:52 by lfantine          #+#    #+#             */
/*   Updated: 2022/12/13 17:45:16 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	chg_cmd_1(t_chain *chain, int j, int len, int i)
{
	while (chain->allcmd[i]->cmd[len + j])
	{
		if (chain->allcmd[i]->cmd[len + j][0] == '<')
		{
			j += 1;
			chain->allcmd[i]->infile = chain->allcmd[i]->cmd[len + j];
			if (!chain->allcmd[i]->infile)
				return (ret_p_error());
			j++;
		}
		else if (chain->allcmd[i]->cmd[len + j][0] == '>')
		{
			j += 1;
			chain->allcmd[i]->outfile = chain->allcmd[i]->cmd[len + j];
			if (!chain->allcmd[i]->outfile)
				return (ret_p_error());
			j++;
		}
		else
			len++;
	}
	return (len);
}

int	chg_cmd_2(t_chain *chain, int j, int len, int i)
{
	if (chain->allcmd[i]->cmd[len + j][0] == '<' &&
		ft_strlen(chain->allcmd[i]->cmd[len + j]) == 1)
	{
		return (1);
	}
	else if (chain->allcmd[i]->cmd[len + j][0] == '>' &&
		ft_strlen(chain->allcmd[i]->cmd[len + j]) == 1)
	{
		return (1);
	}
	else
		return (0);
}

int	change_command(t_chain *chain, int i, int len, int j)
{
	char	**new_cmd;

	while (chain->allcmd[i])
	{
		len = chg_cmd_1(chain, 0, 0, i);
		if (len == -1)
			return (-1);
		new_cmd = malloc(sizeof(char *) * len + 1);
		len = 0;
		while (chain->allcmd[i]->cmd[len + j])
		{
			if (chg_cmd_2(chain, j, len, i) == 1)
				j += 2;
			else
			{
				new_cmd[len] = chain->allcmd[i]->cmd[len + j];
				len++;
			}
		}
		new_cmd[len] = NULL;
		free(chain->allcmd[i]->cmd);
		chain->allcmd[i]->cmd = new_cmd;
		i++;
	}
	return (0);
}

int	make_chains(t_chain *chain, t_data *dta)
{
	int	id;
	int	i;

	i = 0;
	while (chain->allcmd[i])
		i++;
	chain->n_cmd = i;
	i = 0;
	while (chain->allcmd[i])
	{
		id = fork();
		if (id == 0)
		{
			cmd_central(chain, i, dta);
			exit(0);
		}
		wait(NULL);
		i++;
	}
	(void)dta;
	return (0);
}
