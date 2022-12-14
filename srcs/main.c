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
	struct sigaction sa;

	init_dta(&dta, env, argc, argv);
	ft_memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_sigaction = handle_sig;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &sa, NULL);
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

		// if (dta.prompt != NULL)
		// 	print_char_tab_t(dta.prompt);