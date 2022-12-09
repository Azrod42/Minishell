/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_replace_equal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:15:46 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/09 18:29:34 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

size_t	get_len_replace(t_data *dta)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (dta->t_prompt[++i + j])
	{
		if (dta->t_prompt[i] == '$')
			while (dta->t_prompt[i + j] != ' ' && dta->t_prompt[i + j])
				j++;
	}
	return (i - j);
}

void	replace_arg(t_data *dta)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	char	*str;

	i = -1;
	printf("%zu\n", get_len_replace(dta));
	str = malloc(sizeof(char) * get_len_replace(dta));
	if (dta->nb_arg != 0)
	{
		while (dta->t_prompt[++i])
		{
			j = 0;
			if (dta->t_prompt[i] == '$')
			{
				k = -1;
				l = -1;
				while (dta->t_prompt[i + j + 1] != ' ')
					j++;
				while (++k < dta->nb_arg)
					if (ft_strnstr(&dta->t_prompt[i + 1], dta->d_arg[k]->flag, j) != NULL)
						while (dta->d_arg[k]->data[++l]);
							str[i + l] =  dta->d_arg[k]->data[l];
				i += j;
			}
			else
				str[i] = dta->t_prompt[i];
		}
	}
}