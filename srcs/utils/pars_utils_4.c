/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:00:29 by tsorabel          #+#    #+#             */
/*   Updated: 2023/01/03 18:14:51 by tsorabel         ###   ########.fr       */
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
