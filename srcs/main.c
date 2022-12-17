/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/17 16:39:06 by tsorabel         ###   ########.fr       */
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
		if (dta.prompt != NULL)
		{
			check_err(&dta);
			redirect(&dta);
		}
		reset_data(&dta);
	}
	ft_exit(&dta);
	return (0);
}

		// 	print_char_tab_t(dta.prompt);
			//init_triple(&dta);
			//print_t_tab(dta.p);