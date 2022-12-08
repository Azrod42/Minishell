/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:00:29 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/08 22:43:48 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void	add_list(t_data *dta, int i)
{
	t_list	list;
	t_lst	lst;
	int		j;

	i++;
	j = 0;
	while (dta->t_prompt[i + j] != ' ' && dta->t_prompt[i + j])
		j++;
	lst.data = malloc(sizeof(char) * j + 1);
	ft_strlcat(lst.data, &dta->t_prompt[i], j + 1);
	printf("%d\n%s\n", j, lst.data);
	j = 0;
	i -= 1;
	while (dta->t_prompt[i - j] != ' ' && i - j > 0 && dta->t_prompt[i + j])
		j++;
	lst.flag = malloc(sizeof(char) * j + 1);
	ft_strlcat(lst.flag, &dta->t_prompt[i - j], j + 1);
	printf("%d\n%s\n", j, lst.flag);
	list.content = &lst;
	if (dta->list_arg->content == NULL)
	{
		ft_printf("onion");
		dta->list_arg = ft_lstnew(&lst);
	}
	else
		ft_lstadd_back(&dta->list_arg, &list);
}

int	pars_equal(t_data *dta)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (dta->t_prompt[i] != '=')
		i++;
	if (ft_strlen(&dta->t_prompt[i]) > 0)
	{
		if (dta->t_prompt[i - 1] != ' ' && dta->t_prompt[i + 1] != ' ')
			add_list(dta, i);
		if ((dta->t_prompt[i - 1] == ' ' && dta->t_prompt[i + 1] != ' ')
			|| (dta->t_prompt[i - 1] != ' ' && dta->t_prompt[i + 1] == ' '))
		{
			i++;
			while (dta->t_prompt[i] == ' ')
				i++;
			tmp = dta->t_prompt;
			dta->t_prompt = ft_strjoin("", &dta->t_prompt[i]);
			free(tmp);
		}
	}
	return (0);
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
