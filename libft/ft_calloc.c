/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:36:20 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/10 12:30:42 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*c;

	if (nmemb == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	c = malloc(nmemb * size);
	if (!c)
		return (NULL);
	ft_memset(c, 0, nmemb * size);
	return (c);
}
