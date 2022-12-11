/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:30:26 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/11 19:05:00 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	is_wspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	is_sep(char c)
{
	if (c == '\n' || c == ' ')
		return (1);
	return (0);
}

size_t	nb_charinstr(char *str, char c)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == c)
			j++;
	return (j);
}

char	*ft_strnstr_len(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big && len == 0)
		return (0);
	if (!little[i])
		return (((char *)big));
	while (big[i] && i <= len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && little[j] && i + j < len)
					j++;
			if (!little[j] && len == j)
				return (&((char *)big)[i]);
		}
		i++;
	}
	return (NULL);
}

char	*strstr_el(const char *big, const char *little,
	size_t len, size_t ilen)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big && len == 0)
		return (0);
	if (!little[i])
		return (((char *)big));
	while (big[i] && i <= len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && little[j] && i + j < len)
					j++;
			if (!little[j] && ilen == j)
				return (&((char *)big)[i]);
		}
		i++;
	}
	return (NULL);
}
