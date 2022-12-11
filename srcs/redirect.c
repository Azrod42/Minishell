/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:44:54 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/11 16:06:42 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void	redirect(t_data *dta)
{
	size_t	i = -1;
	if (dta->t_prompt[0] != '\0')
	{
		printf("=-=-=");
		while (dta->prompt[++i] != NULL)
			ft_printf("%s/", dta->prompt[i]);
		ft_printf("\n");

		if (ft_strnstr_len(dta->prompt[0], "exit",
				ft_strlen(dta->prompt[0])) != NULL)
			dta->exit = 1;
		else if (ft_strnstr_len(dta->prompt[0], "clear",
				ft_strlen(dta->prompt[0])) != NULL)
			ft_putstr_fd("\e[1;1H\e[2J", 1);
		else
			ft_printf("%s : commande not found\n", dta->prompt[0]);
	}
}
