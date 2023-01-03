/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2023/01/03 11:30:04 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	g_exit_status;

void	main_aux(t_data *dta)
{
	check_err(dta);
	init_triple(dta);
	rm_pipe_t_tab(dta->p);
	redirect(dta);
}

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
		put_env_in_arg(&dta);
		get_prompt_t(&dta);
		if (dta.prompt != NULL)
			main_aux(&dta);
		reset_data(&dta);
	}
	ft_exit(&dta);
	return (0);
}
