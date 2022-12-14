/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/14 15:48:09 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	dta;

	dta.exit = 0;
	dta.nb_arg = 0;
	dta.nb_arg_hist = 0;
	dta.pipe_str = ft_strdup("init");
	get_nickname(&dta, env);
	if (hub_env(&dta, env) == -1)
		exit(1);
	dta.brut_env = env;
	while (!dta.exit)
	{
		geprompt_t(&dta);
		check_err(&dta);
		ft_printf("======FIN_DU_PARS=======\n");
		print_char_tab_t(dta.prompt);
		ft_printf("======FIN_DU_PARS=======\n");
		redirect(&dta);
		reset_data(&dta);
	}
	ft_exit(&dta);
	(void)argc;
	(void)argv;
	return (0);
}
