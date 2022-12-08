/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:23:03 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/08 22:06:50 by tsorabel         ###   ########.fr       */
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
	if (check_equal(dta))
	{
		pars_equal(dta);
		printf("=-%s\n", dta->t_prompt);
	}
	temp = dta->t_prompt;
	dta->t_prompt = ft_strjoin("    ", dta->t_prompt);
	free(temp);
	dta->prompt = ft_split(dta->t_prompt, ' ');
	return (0);
}
