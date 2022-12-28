/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:44:54 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/27 18:41:41 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void	run_cmd_no_pipe(t_data *dta)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		check_redirs(dta);
		take_sig_if_alt(dta);
		execute_cmd(dta);
		if (dta->is_out)
			dup2(dta->back_stdout, STDOUT_FILENO);
		if (dta->is_out)
			close(dta->back_stdout);
		exit(g_exit_status);
	}
	else
	{
		waitpid(pid, &dta->status, 0);
		g_exit_status = WEXITSTATUS(dta->status);
	}
}

void	redirect(t_data *dta)
{
	if (dta->prompt_t[0] != '\0' && dta->exit_actual == 0)
	{
		dta->actual = dta->p[0];
		if (!(ft_strncmp(dta->actual[0], "exit", 5)))
			dta->exit = 1;
		else if (!(ft_strncmp(dta->actual[0], "history", 8)))
			print_historic(dta);
		else if (!(ft_strncmp(dta->actual[0], "export", 7)))
			export(dta);
		else if (!(ft_strncmp(dta->actual[0], "unset", 5)))
			unset(dta, 1);
		else if (!(ft_strncmp(dta->actual[0], "cd", 3)))
			cd(dta);
		else if (!(ft_strncmp(dta->actual[0], "parg", 5)))
			print_arg(dta);
		else if (dta->nb_cmd_p == 1)
			run_cmd_no_pipe(dta);
		else if (dta->nb_cmd_p > 1)
			run_cmd_whith_pipe(dta);
	}
}
			// hub_exec(dta);
