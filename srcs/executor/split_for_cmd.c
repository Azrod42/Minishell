/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_for_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:14:43 by lfantine          #+#    #+#             */
/*   Updated: 2022/12/17 13:21:33 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_elem_cut(char *str)
{
	if ((str[0] == '|' && ft_strlen(str) == 1) || !str)
		return (1);
	return (0);
}

int	cmd_count(t_data *dta)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	while (dta->prompt[i])
	{
		if (is_elem_cut(dta->prompt[i]))
			r++;
		i++;
	}
	return (r);
}

int	nb_elem_cmd(t_data *dta, int start)
{
	int	i;

	i = 0;
	while (dta->prompt[start + i] && is_elem_cut(dta->prompt[start + i]) == 0)
	{
		i++;
	}
	return (i);
}

int	crt_command(t_data *dta, t_chain *chain, int start, int place)
{
	int		i;
	int		len;
	t_cmd	*new_cmd;

	i = 0;
	len = nb_elem_cmd(dta, start);
	new_cmd = malloc(sizeof(t_cmd));
	new_cmd->infile = NULL;
	new_cmd->outfile = NULL;
	new_cmd->cmd = malloc(sizeof (char *) * (len + 1));
	while (i < len)
	{
		new_cmd->cmd[i] = dta->prompt[start + i];
		i++;
	}
	new_cmd->cmd[i] = NULL;
	new_cmd->cmd[0] = replace_cmd_path(new_cmd->cmd[0], dta);
	chain->allcmd[place] = new_cmd;
	return (len);
}

int	make_allcmd(t_chain *chain, t_data *dta)
{
	int	i;
	int	idx;
	int	len;
	int	temp;

	i = 0;
	idx = 0;
	temp = 0;
	len = cmd_count(dta);
	chain->allcmd = malloc(sizeof(t_cmd *) * (len + 1));
	if (!chain->allcmd)
		return (-1);
	while (i < len)
	{
		temp = crt_command(dta, chain, idx, i);
		if (temp == -1)
			break ;
		idx += temp;
		idx++;
		i++;
	}
	chain->allcmd[i] = NULL;
	return (0);
}
