/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:34:13 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/08 17:14:28 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

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

void	reset_data(t_data *dta)
{
	if (dta->prompt != NULL)
		free_tab(dta->prompt);
	if (dta->t_prompt)
		free(dta->t_prompt);
}

void	ft_exit(t_data *dta)
{
	free_tab(dta->prompt);
	system("leaks minishell");
	exit(0);
}
