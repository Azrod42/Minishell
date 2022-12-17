/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_for_cmd2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:14:36 by lfantine          #+#    #+#             */
/*   Updated: 2022/12/17 13:20:30 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*replace_cmd_path(char *old_p, t_data *dta)
{
	int		i;
	char	*new_p;

	i = 0;
	while (dta->env[i])
	{
		new_p = ft_strjoin(dta->env[i], old_p);
		if (access(new_p, X_OK) != -1)
			return (new_p);
		free(new_p);
		i++;
	}
	return (ft_strdup(old_p));
}

//utils
void	free_allcmd(t_chain *chain)
{
	int	i;

	i = 0;
	while (chain->allcmd[i])
	{
		free(chain->allcmd[i]->cmd[0]);
		free(chain->allcmd[i]->cmd);
		free(chain->allcmd[i]);
		i++;
	}
	free(chain->allcmd[i]);
	free(chain->allcmd);
}

void	printf_state(t_chain *chain)
{
	int	k;

	k = 0;
	while (chain->allcmd[k])
	{
		printf("element %d || infile '%s' || outfile '%s'\n",
			k, chain->allcmd[k]->infile, chain->allcmd[k]->outfile);
		print_tab(chain->allcmd[k]);
		k++;
	}
}

int	ret_p_error(void)
{
	printf("parse error\n");
	return (-1);
}
