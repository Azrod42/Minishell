/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:00:29 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/11 12:54:23 by tsorabel         ###   ########.fr       */
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
	while (dta->t_prompt[i + j] != ' ' && dta->t_prompt[i + j])
		j++;
	lst->data = malloc(sizeof(char) * j + 1);
	ft_memcpy(lst->data, &dta->t_prompt[i], j + 1);
	j = 0;
	i -= 2;
	while (dta->t_prompt[i - j] != ' ' && i - j >= 0)
		j++;
	lst->flag = malloc(sizeof(char) * j + 1);
	ft_strlcat(lst->flag, &dta->t_prompt[i - j + 1], j + 1);
	addtab_arg(dta, lst);
	ft_memset(dta->t_prompt, ' ', ft_strlen(lst->data)
		+ ft_strlen(lst->flag) + 1);
}

t_lst	**pars_equal(t_data *dta)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (dta->t_prompt[i] != '=')
		i++;
	if (ft_strlen(&dta->t_prompt[i]) > 0)
	{
		if (!is_sep(dta->t_prompt[i - 1]) && !is_sep(dta->t_prompt[i + 1]))
			add_list(dta, i);
		if ((is_sep(dta->t_prompt[i - 1]) && !is_sep(dta->t_prompt[i + 1]))
			|| (!is_sep(dta->t_prompt[i - 1]) && is_sep(dta->t_prompt[i + 1])))
		{
			i++;
			while (is_sep(dta->t_prompt[i]))
				i++;
			tmp = dta->t_prompt;
			dta->t_prompt = ft_strjoin("", &dta->t_prompt[i]);
			free(tmp);
		}
	}
	return (dta->d_arg);
}

int	check_equal(t_data *dta)
{
	size_t	i;

	i = -1;
	while (dta->t_prompt[++i])
	{
		if (dta->t_prompt[i] == '=')
			return (1);
	}
	return (0);
}

//gerer le cas de + de 1 = ext ARG===test >>>> test not foud