/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_lst_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:03:15 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/27 17:02:32 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

char	**list_to_tab(t_list *lst)
{
	int		i;
	char	**tab;
	t_list	*aux;

	i = 0;
	aux = lst;
	tab = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	while (aux)
	{
		tab[i] = ft_strdup(aux->content);
		aux = aux->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
