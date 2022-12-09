/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:23:03 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/09 17:33:08 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	check_only_space(t_data *dta)
{
	size_t	i;

	i = -1;
	while (dta->t_prompt[++i])
		if (dta->t_prompt[i] != ' ')
			return (1);
	return (0);
}

int	get_prompt(t_data *dta)
{
	dta->t_prompt = readline(USER);
	if (check_equal(dta))
		dta->d_arg = pars_equal(dta);
	if (!check_only_space(dta))
		dta->t_prompt[0] = '\0';
	if (dta->t_prompt[0] == '\0')
	{
		dta->prompt = ft_split("DEL STR", ' ');
		return (0);
	}
	replace_arg(dta);
	dta->prompt = ft_split(dta->t_prompt, ' ');
	return (0);
}
