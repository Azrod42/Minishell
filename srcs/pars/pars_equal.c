/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:00:29 by tsorabel          #+#    #+#             */
/*   Updated: 2023/01/03 11:31:18 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	addtab_arg(t_data *dta, t_lst *lst)
{
	size_t	i;
	t_lst	**n_lst;

	i = dta->nb_arg;
	if (dta->nb_arg != 0)
	{
		n_lst = malloc(sizeof(t_lst *) * (i + 2));
		i = 0;
		while (i < dta->nb_arg)
		{
			n_lst[i] = dta->d_arg[i];
			i++;
		}
		n_lst[i] = lst;
		free(dta->d_arg);
		dta->d_arg = n_lst;
		dta->nb_arg += 1;
	}
	else
	{
		dta->d_arg = malloc(sizeof(t_lst *) * 2);
		dta->d_arg[0] = lst;
		dta->nb_arg = 1;
	}
}

void	add_list(t_data *dta, int i)
{
	t_lst	*lst;
	int		j;

	i++;
	j = 0;
	lst = malloc(sizeof(t_lst) * 1);
	while (dta->prompt_t[i + j] != ' ' && dta->prompt_t[i + j])
		j++;
	lst->data = malloc(sizeof(char) * j + 1);
	ft_memcpy(lst->data, &dta->prompt_t[i], j + 1);
	j = 0;
	i -= 2;
	while (dta->prompt_t[i - j] != ' ' && i - j >= 0)
		j++;
	lst->flag = malloc(sizeof(char) * j + 1);
	ft_strlcat(lst->flag, &dta->prompt_t[i - j + 1], j + 1);
	addtab_arg(dta, lst);
	ft_memset(dta->prompt_t, ' ', ft_strlen(lst->data)
		+ ft_strlen(lst->flag) + 1);
}

t_lst	**pars_equal(t_data *dta)
{
	size_t	i;
	char	*tempo;

	i = 0;
	while (dta->prompt_t[i] != '=')
		i++;
	if (ft_strlen(&dta->prompt_t[i]) > 0)
	{
		if (!is_sep(dta->prompt_t[i - 1]) && !is_sep(dta->prompt_t[i + 1]))
			add_list(dta, i);
		if ((is_sep(dta->prompt_t[i - 1]) && !is_sep(dta->prompt_t[i + 1]))
			|| (!is_sep(dta->prompt_t[i - 1]) && is_sep(dta->prompt_t[i + 1])))
		{
			i++;
			while (is_sep(dta->prompt_t[i]))
				i++;
			tempo = dta->prompt_t;
			dta->prompt_t = ft_strjoin("", &dta->prompt_t[i]);
			free(tempo);
		}
	}
	return (dta->d_arg);
}

int	check_equal(t_data *dta)
{
	size_t	i;

	i = -1;
	while (dta->prompt_t[++i])
	{
		if (is_sep(dta->prompt_t[i]))
			return (0);
		if (dta->prompt_t[i] == '=')
			return (1);
	}
	return (0);
}
