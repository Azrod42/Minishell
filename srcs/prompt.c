/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:23:03 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/11 17:44:13 by tsorabel         ###   ########.fr       */
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
	dta->t_prompt[ft_strlen(dta->t_prompt)] = '\0';
	dta->t_prompt[ft_strlen(dta->t_prompt) + 1] = '\0';
	ft_printf("DEBUG1: %s\n", dta->t_prompt);
	replace_in_quote(dta);
	ft_printf("DEBUG2: %s\n", dta->t_prompt);
	replace_in_simple_quote(dta);
	ft_printf("DEBUG3: %s\n", dta->t_prompt);
	remove_quote(dta);
	ft_printf("DEBUG4: %s\n", dta->t_prompt);
	replace_arg(dta);
	ft_printf("DEBUG5: %s\n", dta->t_prompt);
	if (check_equal(dta))
		dta->d_arg = pars_equal(dta);
	ft_printf("DEBUG6: %s\n", dta->t_prompt);
	if (!check_only_space(dta))
		dta->t_prompt[0] = '\0';
	ft_printf("DEBUG7: %s\n", dta->t_prompt);
	if (dta->t_prompt[0] == '\0')
	{
		dta->prompt = ft_split("EMPTY LINE", ' ');
		return (0);
	}
	dta->prompt = ft_split(dta->t_prompt, ' ');
	replace_special_char(dta);
	return (0);
}
