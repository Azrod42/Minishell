/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/08 18:45:09 by tsorabel         ###   ########.fr       */
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
		reset_data(&dta);
	}
	return (0);
}

//ft_exit(&dta);