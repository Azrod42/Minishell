/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:29:30 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/11 10:10:41 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	is_wspace(char c)
{
	if ((c >= 9 && c<= 13) || c == 32)
		return (1);
	return (0);
}

int is_sep(char c)
{
	if (c == '\n' || c == ' ')
		return (1);
	return (0);
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