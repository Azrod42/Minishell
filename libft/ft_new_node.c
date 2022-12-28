/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:40:54 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/22 11:25:01 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_new_node(void *cont, size_t size)
{
	t_list	*stack;
	void	*aux;

	stack = malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	aux = malloc(size);
	if (!aux)
	{
		free(stack);
		stack = NULL;
	}
	ft_memcpy(aux, cont, size);
	stack->content = aux;
	stack->next = NULL;
	return (stack);
}
