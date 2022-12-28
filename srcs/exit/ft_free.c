/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:34:13 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/28 16:31:46 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	free_tab(char **str)
{
	size_t	i;

	i = -1;
	if (str)
	{
		while (str[++i])
			if (str[i] != NULL)
				free(str[i]);
	}
	free(str);
}

void	free_tab_len(char **str, size_t nb_arg)
{
	size_t	i;

	i = -1;
	if (str)
	{
		while (++i < nb_arg)
			if (str[i] != NULL)
				free(str[i]);
	}
	free(str);
}

void	free_lst(t_lst **lst, t_data *dta)
{
	size_t	i;

	i = -1;
	if (dta->nb_arg != 0)
	{
		while (++i < dta->nb_arg)
		{
			free(lst[i]->data);
			free(lst[i]->flag);
			free(lst[i]);
		}
		free(lst);
	}
}

void	free_triple_tab(char ***tab)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (tab)
	{
		while (tab[++i])
		{
			j = -1;
			while (tab[i][++j])
			{
				if (tab[i][j] != NULL)
					free(tab[i][j]);
			}
			free(tab[i]);
		}
		free(tab);
	}
}

void	free_keys(t_data *dta)
{
	int	i;

	i = -1;
	while (dta->keys[++i])
	{
		if (dta->keys[i] != NULL)
		{
			unlink(dta->keys[i]);
			free(dta->keys[i]);
		}
	}
	free(dta->keys);
}
