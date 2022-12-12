/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/12 18:25:01 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	dta;
	size_t	i;

	i = -1;
	dta.exit = 0;
	dta.nb_arg = 0;
	if (hub_env(&dta, env) == -1)
		exit(1);
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
	(void)argc;
	(void)argv;
	return (0);
}
