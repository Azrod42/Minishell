/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_replace_equal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:15:46 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/09 22:58:56 by tsorabel         ###   ########.fr       */
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
		printf("%c", dta->t_prompt[i + j]);
		if (dta->t_prompt[i + j] == '$')
		{
			while (dta->t_prompt[i + j] != ' ' && dta->t_prompt[i + j] != '\0')
			{
				printf("%c", dta->t_prompt[i + j]);
				j++;
			}
		}
	}
	printf("\n");
	return (i);
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
	if (dta->nb_arg != 0)
	{
		str = malloc(sizeof(char) * get_len_replace(dta));
		while (dta->t_prompt[++i])
		{
			j = 0;
			if (dta->t_prompt[i] == '$')
			{
				k = -1;
				l = -1;
				while (dta->t_prompt[i + j + 1] != ' ' && dta->t_prompt[i + j + 1])
					j++;
				printf("=%zu\n", j);
				while (++k < dta->nb_arg)
				{
					printf("%s\n", ft_strnstr_len(&dta->t_prompt[i + 1], dta->d_arg[k]->flag, j));
					if (ft_strnstr_len(&dta->t_prompt[i + 1], dta->d_arg[k]->flag, j) != NULL)
					{
						printf("find\n");
						while (dta->d_arg[k]->data[++l])
							str[i + l] =  dta->d_arg[k]->data[l];
					}
				}
				i += j;
			}
			else
				str[i] = dta->t_prompt[i];
		}
		printf("%s\n",str);
		free(dta->t_prompt);
		dta->t_prompt = str;
	}
}