/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_nickname.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:20:15 by tsorabel          #+#    #+#             */
/*   Updated: 2023/01/03 18:12:50 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	get_nickname(t_data *dta, char **env)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = -1;
	while (env[++i])
	{
		if (strstr_el(env[i], "LOGNAME=", 18, 7) != NULL)
		{
			j = -1;
			while (env[i][++j] != '=')
				;
			dta->nickname = ft_strdup(&env[i][j + 1]);
			temp = dta->nickname;
			dta->nickname = ft_strjoin("\002\033[0;36m\003", dta->nickname);
			free(temp);
			temp = dta->nickname;
			dta->nickname = ft_strjoin(dta->nickname, "$> \002\033[0;37m\003");
			free(temp);
			return ;
		}
	}
	dta->nickname = ft_strdup(USER);
}
