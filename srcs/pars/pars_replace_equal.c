/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_replace_equal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:15:46 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/12 10:27:01 by tsorabel         ###   ########.fr       */
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
	while (dta->t_prompt[++j])
	{
		if (dta->t_prompt[j] == '$')
		{
			i = -1;
			len = 0;
			j++;
			while (!is_sep(dta->t_prompt[j + len]) && !is_sep(dta->t_prompt
					[j + len] * -1) && dta->t_prompt[j + len])
				len++;
			if (dta->nb_arg == 0)
				dta->t_prompt[j - 1] = dta->t_prompt[j - 1] * -1;
			else
				while (++i < dta->nb_arg)
					if (strstr_el(&dta->t_prompt[j], dta->d_arg[i]->flag,
							ft_strlen(dta->d_arg[i]->flag), len) != NULL)
						dta->t_prompt[j - 1] = dta->t_prompt[j - 1] * -1;
		}
	}
}

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
			while (!is_sep(dta->t_prompt[i + j] * -1)
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
	while (!is_sep(dta->t_prompt[i + j + 1] * -1)
		&& !is_sep(dta->t_prompt[i + j + 1]) && dta->t_prompt
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
		ft_bzero(dta->temp_str_replace_arg, ft_strlen(dta->t_prompt) + 4900);
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
//echo "arguments" "c'est ok" 'oui c"est ok' 'la
//c"est oui' "$ARG" '$ARG' "test$ARG de $ARGde"
//echo "test$ARG de $ARGde"