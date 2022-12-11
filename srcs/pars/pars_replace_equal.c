/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_replace_equal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:15:46 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/10 17:46:48 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

char	*ft_strnstr_len(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big && len == 0)
		return (0);
	if (!little[i])
		return (((char *)big));
	while (big[i] && i <= len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && little[j] && i + j < len)
					j++;
			if (!little[j] && len == j)
				return (&((char *)big)[i]);
		}
		i++;
	}
	return (NULL);
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
			while (dta->t_prompt[i + j] != ' ' && dta->t_prompt[i + j] != '\0')
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
	while (dta->t_prompt[i + j + 1] != ' ' && dta->t_prompt
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
				* ft_strlen(dta->t_prompt));
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