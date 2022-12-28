/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/28 22:02:51 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handler(int sigtype)
{
	if (sigtype == SIGINT)
	{
		g_exit_status = 1;
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	handler2(int sigtype)
{
	if (sigtype == SIGINT)
	{
		write(2, "\n", 1);
		g_exit_status = 130;
	}
	else if (sigtype == SIGQUIT)
	{
		write(2, "Quit: 3\n", 8);
		g_exit_status = 131;
	}
}

void	take_sig_if_alt(t_data *dta)
{
	(void)dta;
	signal(SIGINT, handler2);
	signal(SIGQUIT, handler2);
}

void	handle_sig(int signum, siginfo_t *info, void *ptr)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
	if (signum == SIGQUIT)
	{
		rl_redisplay();
	}
	(void)signum;
	(void)info;
	(void)ptr;
}

void	init_signal(t_data *dta, struct sigaction *sa, struct termios *terminal)
{
	(void)dta;
	ft_memset(sa, 0, sizeof(struct sigaction));
	sa->sa_sigaction = handle_sig;
	sa->sa_flags = SA_SIGINFO;
	dta->keys = NULL;
	sigaction(SIGINT, sa, NULL);
	signal(SIGQUIT, SIG_IGN);
	tcgetattr(STDOUT_FILENO, terminal);
	terminal->c_lflag |= ~ISIG;
	terminal->c_cc[VSUSP] = 0;
	terminal->c_lflag ^= ECHOCTL;
	tcsetattr(STDOUT_FILENO, TCSAFLUSH, terminal);
}

//echo "'$USER'"
//echo "$USER"'$tt'