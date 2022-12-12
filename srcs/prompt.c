/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:23:03 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/12 16:35:41 by tsorabel         ###   ########.fr       */
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
	dta->prompt_t = readline(USER);
	dta->prompt_t[ft_strlen(dta->prompt_t)] = '\0';
	dta->prompt_t[ft_strlen(dta->prompt_t) + 1] = '\0';
	add_historic(dta);
	replace_in_quote(dta);
	replace_in_simple_quote(dta);
	remove_quote(dta);
	if (check_equal(dta))
		dta->d_arg = pars_equal(dta);
	replace_not_in_db(dta);
	replace_arg(dta);
	if (!check_only_space(dta))
		dta->prompt_t[0] = '\0';
	if (dta->prompt_t[0] == '\0')
	{
		dta->prompt = ft_split("EMPTY LINE", ' ');
		return (0);
	}
	dta->prompt = ft_split(dta->prompt_t, ' ');
	replace_special_char(dta);
	return (0);
}

//int i = 0;
//ft_printf("DEBUG[%d]: %s\n", i += 1, dta->prompt_t);

	//print_historic(dta);