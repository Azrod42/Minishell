/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/30 11:52:08 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void	init_dta(t_data *dta, char **env, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	dta->exit = 0;
	dta->nb_arg = 0;
	dta->nb_arg_hist = 0;
	dta->key_done = 0;
	dta->pipe_str = ft_strdup("init");
	dta->empty = ft_strdup("E");
	dta->empty[0] = dta->empty[0] * -1;
	if (hub_env(dta, env) == -1)
		exit(1);
	dta->brut_env = env;
	get_nickname(dta, env);
}
