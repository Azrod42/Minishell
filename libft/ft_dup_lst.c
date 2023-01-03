/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:39:22 by tsorabel          #+#    #+#             */
/*   Updated: 2023/01/03 11:08:58 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_dup_lst(t_list *aux)
{
	t_list	*new_lst;
	t_list	*lst;
	t_list	*tempo;

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
