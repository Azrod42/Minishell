/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/27 19:59:55 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	g_exit_status;

int	main(int argc, char **argv, char **env)
{
	t_data				dta;
	t_list				*envl;
	struct sigaction	sa;
	struct termios		terminal;

	init_dta(&dta, env, argc, argv);
	init_env_list(&dta, &envl, env);
	check_path(&dta);
	update_shlvl(&dta);
	while (!dta.exit)
	{
		init_signal(&dta, &sa, &terminal);
		get_prompt_t(&dta);
		if (dta.prompt != NULL)
		{
			check_err(&dta);
			init_triple(&dta);
			rm_pipe_t_tab(dta.p);
			redirect(&dta);
			unlink(".hd_tempo");
		}
		reset_data(&dta);
	}
	ft_exit(&dta);
	return (0);
}

// print_t_tab(dta.p);