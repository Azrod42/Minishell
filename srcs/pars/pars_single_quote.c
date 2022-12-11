/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_single_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:31:22 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/11 17:17:51 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	replace_in_simple_quote(t_data *dta)
{
	int	nbquote;
	int	i;

	nbquote = 0;
	i = 0;
	while (dta->t_prompt[++i])
		if (dta->t_prompt[i] == '\'')
			nbquote++;
	i = 0;
	while (nbquote > 1)
	{
		while (dta->t_prompt[i] != '\'' && dta->t_prompt[i])
			i++;
		while (dta->t_prompt[++i] != '\'' && dta->t_prompt[i])
			if (is_sep(dta->t_prompt[i]) || dta->t_prompt[i] == '\"'
				|| dta->t_prompt[i] == '$')
				dta->t_prompt[i] = dta->t_prompt[i] * -1;
		nbquote -= 2;
		i++;
	}
}

void	replace_special_char(t_data *dta)
{
	size_t	i;
	size_t	arg;

	arg = -1;
	while (dta->prompt[++arg] != NULL)
	{
		i = -1;
		while (dta->prompt[arg][++i])
			if (dta->prompt[arg][i] < 0)
				dta->prompt[arg][i] = dta->prompt[arg][i] * -1;
	}
}
