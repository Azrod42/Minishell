/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/09 15:27:17 by tsorabel         ###   ########.fr       */
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
	while (!dta.exit)
	{
		get_prompt(&dta);
		redirect(&dta);
		reset_data(&dta);
	}
	while (++i < dta.nb_arg)
		ft_printf("ARG[%d] = FLAG=%s CONTENT=%s\n",
			i, dta.d_arg[i]->flag, dta.d_arg[i]->data);
	ft_exit(&dta);
	return (0);
}