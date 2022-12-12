/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_for_cmd2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:14:36 by lfantine          #+#    #+#             */
/*   Updated: 2022/12/12 18:37:04 by lfantine         ###   ########.fr       */
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
	return (old_p);
}