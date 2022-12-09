/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:23:03 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/09 10:30:43 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	get_prompt(t_data *dta)
{
	char	*temp;

	dta->t_prompt = readline(USER);
	if (dta->t_prompt[0] == '\0')
	{
		dta->prompt = ft_split("DEL STR", ' ');
		return (0);
	}
	temp = dta->t_prompt;
	dta->t_prompt = ft_strjoin("    ", dta->t_prompt);
	free(temp);
	if (check_equal(dta))
		dta->d_arg = pars_equal(dta);
	dta->prompt = ft_split(dta->t_prompt, ' ');
	return (0);
}
