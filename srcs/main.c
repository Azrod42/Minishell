/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/08 10:44:51 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	main(void)
{
	t_data	dta;

	dta.exit = 0;
	while (!dta.exit)
	{
		get_prompt(&dta);
		redirect(&dta);
	}
	ft_exit(&dta);
	return (0);
}
