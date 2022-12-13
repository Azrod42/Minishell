/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_for_cmd2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:14:36 by lfantine          #+#    #+#             */
/*   Updated: 2022/12/13 10:55:38 by lfantine         ###   ########.fr       */
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
