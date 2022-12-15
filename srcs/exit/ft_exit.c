/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:34:13 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/13 17:35:23 by tsorabel         ###   ########.fr       */
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

void	reset_data(t_data *dta)
{
	if (dta->prompt != NULL)
		free_tab(dta->prompt);
	if (dta->prompt_t)
		free(dta->prompt_t);
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
