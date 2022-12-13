/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/13 18:25:51 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	dta;

	dta.exit = 0;
	dta.nb_arg = 0;
	dta.nb_arg_hist = 0;
	get_nickname(&dta, env);
	if (hub_env(&dta, env) == -1)
		exit(1);
	dta.brut_env = env;
	//printf("\e[1;1H\e[2J");
	while (!dta.exit)
	{
		geprompt_t(&dta);
		check_err(&dta);
		redirect(&dta);
		reset_data(&dta);
	}
	ft_exit(&dta);
	(void)argc;
	(void)argv;
	return (0);
}
