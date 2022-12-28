/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:00:29 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/27 17:00:50 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../../include/minishell.h"

void	print_export(t_list **lst, int i)
{
	t_list	*actual;
	char	*str;

	actual = *lst;
	while (actual)
	{
		i = -1;
		str = (char *)actual->content;
		ft_putstr_fd("export ", 1);
		while (str[++i] != '=' && str[i] != '\0')
			ft_putchar_fd(str[i], 1);
		if (str[i] == '\0')
			write(1, "\n", 1);
		else
		{
			ft_putstr_fd("=\"", 1);
			while (str[++i] != '\0')
				ft_putchar_fd(str[i], 1);
			ft_putendl_fd("\"", 1);
		}
		actual = actual->next;
	}
}

void	env(t_data *dta, int is_export)
{
	t_list	*actual;

	if (dta->actual[1] != NULL)
	{
		mess_error(1, "No such file or directory", "");
		return ;
	}
	if (is_export)
	{
		actual = ft_lstdup(*dta->env_list);
		ft_lst_sort(&actual, ft_strcmp);
		print_export(&actual, is_export);
		ft_lst_free(actual);
	}
	else
	{
		actual = (*dta->env_list);
		while (actual)
		{
			if (ft_strchr(actual->content, '='))
				ft_putendl_fd((char *)actual->content, 1);
			actual = actual->next;
		}
	}
}
