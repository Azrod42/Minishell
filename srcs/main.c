/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/12 15:45:42 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	main(void)
{
	t_data	dta;
	size_t	i;

	i = -1;
	dta.exit = 0;
	dta.nb_arg = 0;
	dta.nb_arg_hist = 0;
	printf("\e[1;1H\e[2J");
	while (!dta.exit)
	{
		geprompt_t(&dta);
		redirect(&dta);
		reset_data(&dta);
	}
	i = -1;
	while (++i < dta.nb_arg)
		ft_printf("ARG[%d] = FLAG=%s CONTENT=%s\n",
			i, dta.d_arg[i]->flag, dta.d_arg[i]->data);
	ft_exit(&dta);
	return (0);
}
