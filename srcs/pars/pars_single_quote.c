/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_single_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:31:22 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/12 12:47:31 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	replace_in_simple_quote(t_data *dta)
{
	int	nbquote;
	int	i;

	nbquote = 0;
	i = 0;
	while (dta->prompt_t[++i])
		if (dta->prompt_t[i] == '\'')
			nbquote++;
	i = 0;
	while (nbquote > 1)
	{
		while (dta->prompt_t[i] != '\'' && dta->prompt_t[i])
			i++;
		while (dta->prompt_t[++i] != '\'' && dta->prompt_t[i])
			if (is_sep(dta->prompt_t[i]) || dta->prompt_t[i] == '\"'
				|| dta->prompt_t[i] == '$')
				dta->prompt_t[i] = dta->prompt_t[i] * -1;
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
