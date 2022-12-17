/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/17 14:57:10 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
	sigaction(SIGINT, sa, NULL);
	sigaction(SIGQUIT, sa, NULL);
	tcgetattr(STDOUT_FILENO, terminal);
	terminal->c_lflag |= ~ISIG;
	terminal->c_cc[VSUSP] = 0;
	terminal->c_lflag ^= ECHOCTL;
	tcsetattr(STDOUT_FILENO, TCSAFLUSH, terminal);
}
