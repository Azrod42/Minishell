/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:44:54 by tsorabel          #+#    #+#             */
/*   Updated: 2023/01/05 10:01:53 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void	run_cmd_no_pipe(t_data *dta)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = handle_sig_alt;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &sa, NULL);
	pid = fork();
	if (pid == 0)
	{
		check_redirs(dta);
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
		if (g_exit_status != 130 && g_exit_status != 131)
			g_exit_status = WEXITSTATUS(dta->status);
	}
}

void	triger_exit(t_data *dta, long long number)
{
	int			i;

	i = -1;
	if (dta->p[0][1])
	{
		if (dta->p[0][1][0] == '+' || dta->p[0][1][0] == '-')
			i++;
		while (dta->p[0][1][++i])
		{
			if (!ft_isdigit(dta->p[0][1][i]))
			{
				mess_error(dta, 255, "numeric argument required", "");
				g_exit_status = 255;
				return ;
			}
		}
		number = ft_atoi_long(dta->p[0][1]);
		while (number > 256)
			number -= 256;
		g_exit_status = number;
		return ;
	}
	g_exit_status = 0;
}

void	redirect(t_data *dta)
{
	if (g_exit_status == 130 || g_exit_status == 131)
		g_exit_status = 0;
	if (dta->prompt_t[0] != '\0' && dta->exit_actual == 0)
	{
		dta->actual = dta->p[0];
		if (!(ft_strncmp(dta->actual[0], "exit", 5)))
		{
			triger_exit(dta, 0);
			dta->exit = 1;
		}
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
