/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:00:29 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/30 14:24:53 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	child(t_data *dta, int i, int arg)
{
	check_redirs(dta);
	if (dta->p[arg + 1] != NULL)
	{
		if (!dta->is_out)
			dup2(dta->fd[i % 2][1], STDOUT_FILENO);
	}
	close(dta->fd[i % 2][1]);
	if (i > 0)
	{
		close(dta->fd[i % 2][1]);
		if (!dta->is_in)
			dup2(dta->fd[(i + 1) % 2][0], STDIN_FILENO);
		close(dta->fd[(i + 1) % 2][0]);
	}
	close(dta->fd[i % 2][0]);
	if (dta->is_out)
		close(dta->back_stdout);
	if (dta->actual[0])
	{
		if (is_builtin(dta) && !dta->nb_cmd_p)
			exit (g_exit_status);
		else
			execute_cmd(dta);
	}
	exit (g_exit_status);
}

void	run_cmd_whith_pipe_2(t_data *dta, int i, int *flag, int arg)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		close(dta->fd[i % 2][1]);
		close(dta->fd[i % 2][0]);
		*flag = 1;
	}
	if (pid == 0)
		child(dta, i, arg);
	close(dta->fd[i % 2][1]);
	if (i > 0 && dta->p[arg + 1] != NULL)
		close(dta->fd[(i + 1) % 2][0]);
	if (i > 0 && dta->p[arg + 1] == NULL)
	{
		close(dta->fd[i % 2][0]);
		close(dta->fd[(i + 1) % 2][0]);
	}
	if (i == 0 && dta->p[arg + 1] == NULL)
		close(dta->fd[i % 2][0]);
}

void	kill_last_process(t_data *dta, int flag)
{
	int	nb_pipe;

	nb_pipe = dta->nb_cmd_p - 1;
	if (flag)
		mess_error(dta, -1, "Fork error", "");
	while (nb_pipe >= 0)
	{
		waitpid(-1, &dta->status, 0);
		if (WIFEXITED(dta->status))
			g_exit_status = WEXITSTATUS(dta->status);
		nb_pipe--;
	}
	if (g_exit_status == 250)
		g_exit_status = 1;
}

void	run_cmd_whith_pipe(t_data *dta)
{
	int	i;
	int	arg;
	int	flag;

	i = 0;
	arg = -1;
	flag = 0;
	while (dta->p[++arg] && WIFEXITED(dta->status))
	{
		if (pipe(dta->fd[i % 2]) == -1)
			mess_error(dta, -1, "Pipe ", "error");
		dta->actual = dta->p[arg];
		run_cmd_whith_pipe_2(dta, i, &flag, arg);
		take_sig_if_alt(dta);
		i++;
	}
	kill_last_process(dta, flag);
}
