/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:27:37 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/12 18:49:51 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	add_after_pipe(t_data *dta)
{
	char	*str;
	char	*temp;
	size_t	i;

	while (1)
	{
		str = readline("\033[0;32mpipe>\033[0;37m");
		i = -1;
		while (str[++i])
		{
			if (!is_sep(str[i]))
			{
				temp = ft_strjoin(dta->prompt_t, str);
				printf("=%s\n", temp);
				free(dta->prompt_t);
				dta->prompt_t = temp;
				free(str);
				return ;
			}
		}
		free(str);
	}
}

int	check_last_char(char *str, char c)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (is_sep(str[i]))
		i--;
	if (str[i] == c)
		return (1);
	return (0);
}

void	check_end_pipe(t_data *dta)
{
	if (dta->prompt_t[0] == '\0')
		return ;
	while (check_last_char(dta->prompt_t, '|'))
		add_after_pipe(dta);
}

void	replace_pipe(t_data *dta)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = -1;
	j = 0;
	new = malloc(sizeof(char) * (nb_charinstr(dta
					->prompt_t, '|') * 2) + ft_strlen(dta->prompt_t));
	while (dta->prompt_t[++i])
	{
		if (dta->prompt_t[i] == '|')
		{
			new[j] = ' ';
			new[j + 1] = '|';
			new[j + 2] = ' ';
			j += 2;
		}
		else
			new[j] = dta->prompt_t[i];
		j++;
	}
	new[j] = '\0';
	free(dta->prompt_t);
	dta->prompt_t = new;
}