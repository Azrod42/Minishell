/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/16 21:36:28 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data				dta;
	struct sigaction	sa;
	struct termios		terminal;

	init_dta(&dta, env, argc, argv);
	init_signal(&dta, &sa, &terminal);
	while (!dta.exit)
	{
		geprompt_t(&dta);
		ft_printf("ok\n");
		check_err(&dta);
		if (dta.prompt != NULL)
			print_char_tab_t(dta.prompt);
		ft_printf("ok\n");
		if (dta.prompt != NULL)
			init_triple(&dta);
		ft_printf("ok\n");
		if (dta.prompt != NULL)
			print_t_tab(dta.p);
		if (dta.prompt != NULL)
			print_char_tab_t(dta.prompt);
		//redirect(&dta);
		reset_data(&dta);
	}
	ft_exit(&dta);
	(void)argc;
	(void)argv;
	return (0);
}

		// if (dta.prompt != NULL)
		// 	print_char_tab_t(dta.prompt);