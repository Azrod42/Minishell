/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_existing_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:59:40 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/14 15:46:47 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	print_arg(t_data *dta)
{
	size_t	i;

	i = -1;
	while (++i < dta->nb_arg)
		ft_printf("ARG[%d] = FLAG=%s CONTENT=%s\n",
			i, dta->d_arg[i]->flag, dta->d_arg[i]->data);
}

void	replace_existing_arg(t_data *dta)
{
	int	i;
	int	j;

	i = dta->nb_arg - 1;
	if (dta->nb_arg < 2)
		return ;
	while (i > 0)
	{
		j = i;
		while (--j >= 0)
		{
			if (ft_memcmp(dta->d_arg[i]->flag,
					dta->d_arg[j]->flag, ft_strlen(dta->d_arg[i]->flag)) == 0)
			{
				if (dta->d_arg[j]->data)
					free(dta->d_arg[j]->data);
				dta->d_arg[j]->data = ft_strdup(dta->d_arg[i]->data);
			}
		}
		i--;
	}
}
