/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:34:13 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/28 16:29:22 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../../include/minishell.h"

void	reset_data(t_data *dta)
{
	if (dta->p != NULL && dta->prompt != NULL)
		free_triple_tab(dta->p);
	if (dta->prompt != NULL)
		free_tab(dta->prompt);
	free(dta->prompt_t);
	if (dta->keys != NULL)
		free_keys(dta);
}

void	ft_exit(t_data *dta)
{
	free_lst(dta->d_arg, dta);
	if (dta->nb_arg_hist)
		free_tab(dta->historique);
	free(dta->nickname);
	system("leaks minishell");
	close(0);
	close(1);
	close(2);
	exit(0);
}
