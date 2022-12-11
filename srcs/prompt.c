/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:23:03 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/11 13:55:16 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	check_only_space(t_data *dta)
{
	size_t	i;

	i = -1;
	while (dta->t_prompt[++i])
		if (!is_sep(dta->t_prompt[i]))
			return (1);
	return (0);
}

int	get_prompt(t_data *dta)
{
	dta->t_prompt = readline(USER);
	replace_in_quote(dta);
	replace_in_simple_quote(dta);
	remove_quote(dta);
	replace_arg(dta);
	if (check_equal(dta))
		dta->d_arg = pars_equal(dta);
	if (!check_only_space(dta))
		dta->t_prompt[0] = '\0';
	if (dta->t_prompt[0] == '\0')
	{
		dta->prompt = ft_split("EMPTY LINE", ' ');
		return (0);
	}
	dta->prompt = ft_split(dta->t_prompt, ' ');
	return (0);
}
