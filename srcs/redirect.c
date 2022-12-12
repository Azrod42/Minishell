/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:44:54 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/12 12:52:42 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void	redirect(t_data *dta)
{
	size_t	i;
	i = -1;
	if (dta->prompt_t[0] != '\0')
	{
		while (dta->prompt[++i] != NULL)
			ft_printf("%s~~", dta->prompt[i]);
		ft_printf("\n");
		if (strstr_el(dta->prompt[0], "exit",
				ft_strlen(dta->prompt[0]), 3) != NULL)
			dta->exit = 1;
		else if (strstr_el(dta->prompt[0], "clear",
				ft_strlen(dta->prompt[0]), 4) != NULL)
			ft_putstr_fd("\e[1;1H\e[2J", 1);
		else
			ft_printf("%s : commande not found\n", dta->prompt[0]);
	}
}