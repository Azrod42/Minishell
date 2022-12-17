/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_replace_equal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:15:46 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/17 17:33:05 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	replace_not_in_db(t_data *dta)
{
	size_t	i;
	size_t	j;
	size_t	len;

	j = -1;
	len = 0;
	while (dta->prompt_t[++j])
	{
		if (dta->prompt_t[j] == '$')
		{
			i = -1;
			len = 0;
			j++;
			while (!is_sep(dta->prompt_t[j + len]) && !is_sep(dta->prompt_t
					[j + len] * -1) && dta->prompt_t[j + len])
				len++;
			if (dta->nb_arg == 0)
				dta->prompt_t[j - 1] = dta->prompt_t[j - 1] * -1;
			else
				while (++i < dta->nb_arg)
					if (strstr_el(&dta->prompt_t[j], dta->d_arg[i]->flag,
							ft_strlen(dta->d_arg[i]->flag), len) != NULL)
						dta->prompt_t[j - 1] = dta->prompt_t[j - 1] * -1;
		}
	}
}

size_t	get_len_replace(t_data *dta)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (dta->prompt_t[++i + j])
	{
		if (dta->prompt_t[i + j] == '$')
		{
			while (!is_sep(dta->prompt_t[i + j] * -1)
				&& dta->prompt_t[i + j] != '\0')
			{
				j++;
			}
		}
	}
	return (i);
}

size_t	replace_arg_2(t_data *dta, size_t i, size_t *m)
{
	size_t	k;
	size_t	l;
	size_t	j;

	k = -1;
	j = 0;
	while (!is_sep(dta->prompt_t[i + j + 1] * -1)
		&& !is_sep(dta->prompt_t[i + j + 1]) && dta->prompt_t
		[i + j + 1] != '$' && dta->prompt_t[i + j + 1])
		j++;
	while (++k < dta->nb_arg)
	{
		l = -1;
		if (ft_strnstr_len(&dta->prompt_t[i + 1],
				dta->d_arg[k]->flag, j) != NULL)
		{
			while (dta->d_arg[k]->data[++l])
			{
				dta->temp_str_replace_arg[*m] = dta->d_arg[k]->data[l];
				*m += 1;
			}
			return (j);
		}
	}
	return (j);
}

void	replace_arg(t_data *dta)
{
	size_t	i;
	size_t	m;

	i = -1;
	m = 0;
	if (dta->nb_arg != 0)
	{
		dta->temp_str_replace_arg = malloc(sizeof(char)
				* ft_strlen(dta->prompt_t) + 10000);
		ft_bzero(dta->temp_str_replace_arg, ft_strlen(dta->prompt_t) + 8000);
		while (dta->prompt_t[++i])
		{
			if (dta->prompt_t[i] == '$')
				i += replace_arg_2(dta, i, &m);
			else
			{
				dta->temp_str_replace_arg[m] = dta->prompt_t[i];
				m++;
			}
		}
		free(dta->prompt_t);
		dta->prompt_t = ft_strdup(dta->temp_str_replace_arg);
		free(dta->temp_str_replace_arg);
	}
}

//a gerer le cas d'un $arg=test >>>>>> $$arg doit etre = a $arr
//echo "arguments" "c'est ok" 'oui c"est ok' 'la
//c"est oui' "$ARG" '$ARG' "test$ARG de $ARGde"
//echo "test$ARG de $ARGde"