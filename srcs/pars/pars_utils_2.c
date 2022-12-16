/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:30:26 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/12 10:32:57 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	check_last_char(char *str, char c)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (is_sep(str[i]))
		i--;
	if (str[i] == c)
		return (1);
	return (0);
}

int	is_sep_mix(char c)
{
	if (c == '>' || c == '<')
		return (1);
	return (0);
}

int	check_fst_c(char *str)
{
	size_t	i;

	i = -1;
	while (is_sep(str[++i]))
		;
	if (str[i] != '\0')
		return (str[i]);
	return (0);
}

int	is_to_space(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}
