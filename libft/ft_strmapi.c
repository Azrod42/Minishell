/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:44:47 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/10 09:44:48 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*c;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = -1;
	c = malloc((ft_strlen(s) + 1));
	if (!c)
		return (NULL);
	while (++i < ft_strlen(s))
		c[i] = f(i, s[i]);
	c[i] = '\0';
	return (c);
}
