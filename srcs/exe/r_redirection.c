/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_redirection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:00:29 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/27 17:01:24 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	r_redirection(t_data *dta, int i)
{
	char	**actual;
	int		j;

	j = -1;
	actual = malloc(sizeof(char *) * (tab_len(dta->actual) - 1));
	while (dta->actual[++j] && j < i)
		actual[j] = ft_strdup(dta->actual[j]);
	i += 2;
	while (dta->actual[i])
		actual[j++] = ft_strdup(dta->actual[i++]);
	actual[j] = NULL;
	dta->actual = NULL;
	dta->actual = actual;
}
