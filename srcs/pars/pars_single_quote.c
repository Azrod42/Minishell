/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_single_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:31:22 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/11 14:13:13 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	replace_in_simple_quote(t_data *dta)
{
	int	nbquote;
	int	nbdquote;
	int	i;

	nbquote = 0;
	nbdquote = 0;
	i = -1;
	while (dta->t_prompt[++i])
		if (dta->t_prompt[i] == '\'')
			nbquote++;
	while (nbquote > 1)
	{
		i = -1;
		while (dta->t_prompt[++i] != '\'')
			if (dta->t_prompt[i] == '\"')
				nbdquote++;
		while (dta->t_prompt[++i] != '\'')
		{
			if (dta->t_prompt[i] == '\"')
				nbdquote++;
			if (is_sep(dta->t_prompt[i]) || (dta->t_prompt[i] == '$' && nbdquote % 2 != 0))
				dta->t_prompt[i] = dta->t_prompt[i] * -1;
		}
		nbquote -= 2;
	}
}
