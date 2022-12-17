/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:34:13 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/17 15:02:18 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	reset_data(t_data *dta)
{
	(void)dta;
	if (dta->p != NULL && dta->prompt != NULL)
		free_triple_tab(dta->p);
	if (dta->prompt != NULL)
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
