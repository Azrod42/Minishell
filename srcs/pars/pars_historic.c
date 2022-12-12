/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_historic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:03:15 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/12 16:25:09 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	init_historic(t_data *dta, char *new)
{
	dta->historique = malloc(sizeof(char *) * 2);
	dta->historique[0] = new;
	dta->nb_arg_hist = 1;
}

void	print_historic(t_data *dta)
{
	size_t	arg;
	size_t	i;

	arg = -1;
	i = 0;
	while (++arg < dta->nb_arg_hist)
		printf("[%05zu]: %s\n", i += 1, dta->historique[arg]);
}

void	add_historic(t_data *dta)
{
	size_t	i;
	char	*new;
	char	**n_lst;

	i = dta->nb_arg_hist;
	new = malloc(sizeof(char) * (ft_strlen(dta->prompt_t) + 2));
	ft_strlcat(new, dta->prompt_t, ft_strlen(dta->prompt_t) + 1);
	if (dta->nb_arg_hist != 0)
	{
		n_lst = malloc(sizeof(char *) * (i + 2));
		i = 0;
		while (i < dta->nb_arg_hist)
		{
			n_lst[i] = dta->historique[i];
			i++;
		}
		n_lst[i] = new;
		free(dta->historique);
		dta->historique = n_lst;
		dta->nb_arg_hist += 1;
	}
	else
		init_historic(dta, new);
}
