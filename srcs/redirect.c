/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:44:54 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/13 11:39:36 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void	redirect(t_data *dta)
{
	if (dta->prompt_t[0] != '\0')
	{
		if (strstr_el(dta->prompt[0], "exit",
				ft_strlen(dta->prompt[0]), 3) != NULL)
			dta->exit = 1;
		else if (strstr_el(dta->prompt[0], "clear",
				ft_strlen(dta->prompt[0]), 4) != NULL)
			ft_putstr_fd("\e[1;1H\e[2J", 1);
		else if (strstr_el(dta->prompt[0], "history",
				ft_strlen(dta->prompt[0]), 6) != NULL)
			print_historic(dta);
		else if (strstr_el(dta->prompt[0], "parg",
				ft_strlen(dta->prompt[0]), 3) != NULL)
			print_arg(dta);
		else
			hub_exec(dta);
	}
}
