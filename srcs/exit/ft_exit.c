/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:34:13 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/16 18:15:09 by tsorabel         ###   ########.fr       */
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

void	reset_data(t_data *dta)
{
	(void)dta;
	if (dta->p)
		free_triple_tab(dta->p);
	if (dta->prompt)
		free_tab(dta->prompt);
}

void	ft_exit(t_data *dta)
{
	free_lst(dta->d_arg, dta);
	if (dta->nb_arg_hist != 0)
		free_tab_len(dta->historique, dta->nb_arg_hist);
	free_tab(dta->env);
	free(dta->nickname);
	system("leaks minishell");
	exit(0);
}
