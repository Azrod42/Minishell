/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:34:13 by tsorabel          #+#    #+#             */
/*   Updated: 2023/01/05 16:49:49 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../../include/minishell.h"

void	del_key(void *s)
{
	char	*str;

	str = (char *)s;
	unlink(str);
	free(str);
}

void	reset_data(t_data *dta)
{
	if (dta->p != NULL && dta->prompt != NULL)
		free_triple_tab(dta->p);
	if (dta->prompt != NULL)
		free_tab(dta->prompt);
	if (dta->prompt_t)
		free(dta->prompt_t);
	if (dta->keys != NULL)
		free_keys(dta);
	if (dta->key_to_free)
		ft_lstclear(&dta->key_to_free, del_key);
}

void	ft_exit(t_data *dta)
{
	(void)dta;
	if (dta->d_arg != NULL)
		free_lst(dta->d_arg, dta);
	if (dta->nb_arg_hist > 0)
		free_tab_len(dta->historique, dta->nb_arg_hist);
	if (dta->nickname != NULL)
		free(dta->nickname);
	system("leaks minishell");
	close(0);
	close(1);
	close(2);
	exit(g_exit_status);
}
