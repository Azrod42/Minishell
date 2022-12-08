/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:34:13 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/08 10:45:12 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void	free_tab(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
}

void	ft_exit(t_data *dta)
{
	free_tab(dta->prompt);
	system("leaks minishell");
	exit(0);
}
