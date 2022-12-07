/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:42:03 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/10 09:42:03 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(char const *s)
{
	char	*dup;

	dup = malloc((ft_strlen(s) + 1) * 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, ft_strlen(s));
	dup[ft_strlen(s)] = '\0';
	return (dup);
}
