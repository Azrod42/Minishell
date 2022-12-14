/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:23:03 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/14 15:35:17 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	check_only_space(t_data *dta)
{
	size_t	i;

	i = -1;
	while (dta->prompt_t[++i])
		if (!is_sep(dta->prompt_t[i]))
			return (1);
	return (0);
}

int	geprompt_t(t_data *dta)
{
	int i = 0;
	dta->exit_actual = 0;
	dta->prompt_t = readline(dta->nickname);
	ft_printf("DEBUG[%d]: %s\n", i += 1, dta->prompt_t);
	check_end_pipe(dta);
	ft_printf("DEBUG[%d]: %s\n", i += 1, dta->prompt_t);
	space_spe_char(dta);
	ft_printf("DEBUG[%d]: %s\n", i += 1, dta->prompt_t);
	replace_pipe(dta);
	ft_printf("DEBUG[%d]: %s\n", i += 1, dta->prompt_t);
	add_historic(dta);
	replace_in_quote(dta);
	replace_in_simple_quote(dta);
	remove_quote(dta);
	if (check_equal(dta))
		dta->d_arg = pars_equal(dta);
	replace_existing_arg(dta);
	replace_not_in_db(dta);
	replace_arg(dta);
	if (!check_only_space(dta))
		dta->prompt_t[0] = '\0';
	if (dta->prompt_t[0] == '\0')
	{
		dta->prompt = NULL;
		return (0);
	}
	dta->prompt = ft_split(dta->prompt_t, ' ');
	replace_special_char(dta);
	replace_special_char_in_arg(dta);
	return (0);
}

//int i = 0;
//ft_printf("DEBUG[%d]: %s\n", i += 1, dta->prompt_t);

	//print_historic(dta);