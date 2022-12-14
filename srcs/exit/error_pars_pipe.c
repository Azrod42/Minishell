/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pars_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:47:48 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/14 15:48:22 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	check_first_pipe(t_data *dta)
{
	size_t	i;

	i = -1;
	if (dta->prompt_t[0] == '\0')
		return (1);
	while (is_sep(dta->prompt[0][++i]))
		;
	if (dta->prompt[0][i] == '|')
	{
		dta->exit_actual = 1;
		ft_printf("\033[0;31mminishell :");
		ft_printf(" syntax error near  \'|\'\033[0;37m\n");
		return (1);
	}
	return (0);
}

void	check_err_pipe(t_data *dta)
{
	size_t	arg;
	size_t	i;

	arg = -1;
	if (check_first_pipe(dta) == 1 || dta->prompt_t[0] == '\0')
		return ;
	while (dta->prompt[++arg])
	{
		i = -1;
		while (is_sep(dta->prompt[arg][++i]))
			;
		if (dta->prompt[arg][i] == '|')
		{
			i = -1;
			arg++;
			while (is_sep(dta->prompt[arg][++i]))
				;
			if (dta->prompt[arg][i] == '|')
			{
				dta->exit_actual = 1;
				ft_printf("\033[0;31mminishell :");
				ft_printf(" syntax error near  \'|\'\033[0;37m\n");
			}
		}
	}
}

void	check_err(t_data *dta)
{
	check_err_pipe(dta);
}
