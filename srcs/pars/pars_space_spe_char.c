/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_space_spe_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:27:37 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/17 09:31:38 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

size_t	nb_char_to_add(t_data *dta)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (dta->prompt_t[++i])
	{
		if (is_to_space(dta->prompt_t[i]))
		{
			if (is_to_space(dta->prompt_t[i + 1]))
				i++;
			j += 2;
		}
	}
	return (j);
}

void	one_sign(char *n, int *j, char c)
{
			n[*j] = ' ';
			n[*j + 1] = c;
			n[*j + 2] = ' ';
			*j += 2;
}

void	two_sign(char *n, int *j, char c, int *i)
{
			n[*j] = ' ';
			n[*j + 1] = c;
			n[*j + 2] = c;
			n[*j + 3] = ' ';
			*j += 3;
			*i += 1;
}

void	space_spe_char(t_data *dta)
{
	int		i;
	int		j;
	char	*n;

	i = -1;
	j = 0;
	n = malloc(sizeof(char) * (nb_char_to_add(dta) + ft_strlen(dta->prompt_t)));
	while (dta->prompt_t[++i])
	{
		if (is_to_space(dta->prompt_t[i]))
		{
			if (dta->prompt_t[i + 1] == dta->prompt_t[i])
				two_sign(n, &j, dta->prompt_t[i], &i);
			else
				one_sign(n, &j, dta->prompt_t[i]);
		}
		else
			n[j] = dta->prompt_t[i];
		j++;
	}
	n[j] = '\0';
	dta->secure_len = ft_strlen(dta->prompt_t);
	free(dta->prompt_t);
	dta->prompt_t = n;
}

void	replace_tab(t_data *dta)
{
	size_t	i;

	i = -1;
	while (dta->prompt_t[++i])
		if (dta->prompt_t[i] == '\t')
			dta->prompt_t[i] = ' ';
}
