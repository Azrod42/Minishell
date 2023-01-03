/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2023/01/03 11:38:15 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_sig_alt(int signum, siginfo_t *info, void *ptr)
{
	if (signum == SIGINT)
	{
		write(2, "\n", 1);
		g_exit_status = 130;
	}
	if (signum == SIGQUIT)
	{
		write(2, "Quit: 3\n", 8);
		g_exit_status = 131;
	}
	(void)signum;
	(void)info;
	(void)ptr;
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
	dta->key_done = 0;
	sigaction(SIGINT, sa, NULL);
	signal(SIGQUIT, SIG_IGN);
	tcgetattr(STDOUT_FILENO, terminal);
	terminal->c_lflag |= ~ISIG;
	terminal->c_cc[VSUSP] = 0;
	terminal->c_lflag ^= ECHOCTL;
	tcsetattr(STDOUT_FILENO, TCSAFLUSH, terminal);
}
