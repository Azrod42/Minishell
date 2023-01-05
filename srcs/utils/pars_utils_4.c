/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:00:29 by tsorabel          #+#    #+#             */
/*   Updated: 2023/01/05 16:47:23 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	replace_tab(t_data *dta)
{
	size_t	i;
	char	*t;

	i = -1;
	while (dta->prompt_t[++i])
		if (dta->prompt_t[i] == '\t')
			dta->prompt_t[i] = ' ';
	t = dta->prompt_t;
	dta->prompt_t = ft_strjoin(dta->prompt_t, "     ");
	free(t);
	t = dta->prompt_t;
	dta->prompt_t = ft_strjoin(" ", dta->prompt_t);
	free(t);
}

void	stop_handle(t_data *dta, int i)
{
	while (dta->prompt_t[++i])
		if (is_to_space(dta->prompt_t[i] * -1))
			dta->prompt_t[i] = dta->prompt_t[i] * -1;
}

void	handle_in_quote(t_data *dta, int i)
{
	int	in;
	int	in2;

	in = -1;
	in2 = -1;
	while (dta->prompt_t[++i])
	{
		if (dta->prompt_t[i] == '"' && in2 == -1)
			in *= -1;
		if (dta->prompt_t[i] == '\'' && in == -1)
			in2 *= -1;
		if (is_to_space(dta->prompt_t[i]) && (in == 1 || in2 == 1))
			dta->prompt_t[i] = dta->prompt_t[i] * -1;
	}
}
