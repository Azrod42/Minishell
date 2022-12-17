/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pars_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:47:48 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/17 16:36:15 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	check_first_pipe(t_data *dta)
{
	int	i;

	i = -1;
	if (dta->prompt_t[0] == '\0')
		return (1);
	while (is_sep(dta->prompt[0][++i]))
		;
	if (dta->prompt[0][i] == '|' && dta->exit_actual == 0)
	{
		dta->exit_actual = 1;
		print_error("syntax error near", "|");
		return (1);
	}
	return (0);
}

void	check_err_pipe(t_data *dta)
{
	int	arg;
	int	i;

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
			if (dta->prompt[arg][i] == '|' && dta->exit_actual == 0)
			{
				dta->exit_actual = 1;
				print_error("syntax error near", "|");
			}
		}
	}
}

void	check_err_before_pipe(t_data *dta)
{
	int	arg;

	arg = -1;
	if (is_to_space(dta->prompt[0][0]))
		arg++;
	while (dta->prompt[++arg] && dta->exit_actual == 0)
	{
		if (is_to_space(dta->prompt[arg][0]) && (is_to_space(dta->
				prompt[arg + 1][0]) || is_to_space(dta->prompt[arg - 1][0])))
		{
			dta->exit_actual = 1;
			print_error("syntax error near", dta->prompt[arg]);
		}
	}
}

void	check_err(t_data *dta)
{
	check_err_pipe(dta);
	check_err_before_pipe(dta);
}
