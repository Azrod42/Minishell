/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_replace_equal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:15:46 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/11 11:41:17 by tsorabel         ###   ########.fr       */
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
		if (dta->t_prompt[i + j] == '$')
		{
			while (!is_sep(dta->t_prompt[i + j])
				&& dta->t_prompt[i + j] != '\0')
			{
				j++;
			}
		}
	}
	return (i);
}

size_t	replace_arg_2(t_data *dta, size_t i, size_t j, size_t *m)
{
	size_t	k;
	size_t	l;

	k = -1;
	while (!is_sep(dta->t_prompt[i + j + 1]) && dta->t_prompt
		[i + j + 1] != '$' && dta->t_prompt[i + j + 1])
		j++;
	while (++k < dta->nb_arg)
	{
		l = -1;
		if (ft_strnstr_len(&dta->t_prompt[i + 1],
				dta->d_arg[k]->flag, j) != NULL)
		{
			while (dta->d_arg[k]->data[++l])
			{
				dta->temp_str_replace_arg[*m] = dta->d_arg[k]->data[l];
				*m += 1;
			}
		}
	}
	return (j);
}

void	replace_arg(t_data *dta)
{
	size_t	i;
	size_t	j;
	size_t	m;

	i = -1;
	m = 0;
	if (dta->nb_arg != 0)
	{
		dta->temp_str_replace_arg = malloc(sizeof(char)
				* ft_strlen(dta->t_prompt) + 5000);
		ft_bzero(dta->temp_str_replace_arg, ft_strlen(dta->t_prompt) + 4990);
		while (dta->t_prompt[++i])
		{
			j = 0;
			if (dta->t_prompt[i] == '$' && dta->t_prompt[i + 1] != '$')
				i += replace_arg_2(dta, i, j, &m);
			else
			{
				dta->temp_str_replace_arg[m] = dta->t_prompt[i];
				m++;
			}
		}
		free(dta->t_prompt);
		dta->t_prompt = dta->temp_str_replace_arg;
	}
}

//a gerer le cas d'un $arg=test >>>>>> $$arg doit etre = a $arr