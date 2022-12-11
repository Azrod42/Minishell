/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:44:54 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/11 10:11:28 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void	redirect(t_data *dta)
{
	if (dta->t_prompt[0] != '\0')
	{
		if (ft_strnstr_len(dta->prompt[0], "exit",
				ft_strlen(dta->prompt[0])) != NULL)
			dta->exit = 1;
		else if (ft_strnstr(dta->prompt[0], "clear",
				ft_strlen_len(dta->prompt[0])) != NULL)
			ft_putstr_fd("\e[1;1H\e[2J", 1);
		else
			printf("%s : commande not found\n", dta->prompt[0]);
	}
}
