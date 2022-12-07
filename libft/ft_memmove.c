/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:40:45 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/10 09:40:46 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*c;
	char	*d;

	i = -1;
	c = dest;
	d = (char *)src;
	if ((!dest && !src) || n == 0)
		return (dest);
	if (dest < src)
	{
		while (++i < n)
			*(c++) = *(d++);
	}
	else
	{
		c = c + (n - 1);
		d = d + (n - 1);
		while (++i < n)
			*(c--) = *(d--);
	}
	return (dest);
}
