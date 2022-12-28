/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:39:22 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/26 13:13:04 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstdup(t_list *aux)
{
	t_list	*new_lst;
	t_list	*tempo;
	t_list	*lst;

	new_lst = 0;
	lst = aux;
	while (lst)
	{
		tempo = ft_lstnew(lst->content);
		if (!tempo)
			return (0);
		ft_lstadd_back(&new_lst, tempo);
		lst = lst->next;
	}
	return (new_lst);
}