/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:31:22 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/11 14:44:28 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	replace_in_quote(t_data *dta)
{
	int	nbquote;
	int	i;

	nbquote = 0;
	i = -1;
	while (dta->t_prompt[++i])
		if (dta->t_prompt[i] == '\"')
			nbquote++;
	while (nbquote > 1)
	{
		i = 0;
		while (dta->t_prompt[i] != '\"')
			i++;
		while (dta->t_prompt[++i] != '\"')
			if (is_sep(dta->t_prompt[i]))
				dta->t_prompt[i] = dta->t_prompt[i] * -1;
		nbquote -= 2;
	}
}

size_t	get_len_remove_quote(t_data *dta)
{
	size_t	i;
	size_t	trm;

	i = -1;
	trm = 0;
	while (dta->t_prompt[++i])
	{
		if (dta->t_prompt[i] == '\'')
		{
			while (dta->t_prompt[++i] != '\'' && dta->t_prompt[i])
				;
			if (dta->t_prompt[i] == '\'')
				trm += 2;
			i++;
		}
		else if (dta->t_prompt[i] == '\"')
		{
			while (dta->t_prompt[++i] != '\"' && dta->t_prompt[i])
				;
			if (dta->t_prompt[i] == '\"')
				trm += 2;
			i++;
		}
	}
	return (trm);
}

void	remove_quote(t_data *dta)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	i = -1;
	j = 0;
	k = 0;
	new = malloc(sizeof(char) * (ft_strlen(dta->t_prompt)
				- get_len_remove_quote(dta)));
	while (dta->t_prompt[++i])
	{
		if (dta->t_prompt[i] == '\'')
			while (dta->t_prompt[++i] != '\'' && dta->t_prompt[i])
				new[k++] = dta->t_prompt[i];
		else if (dta->t_prompt[i] == '\"')
			while (dta->t_prompt[++i] != '\"' && dta->t_prompt[i])
				new[k++] = dta->t_prompt[i];
		else
			new[k++] = dta->t_prompt[i];
		if (dta->t_prompt[i] == '\"' || dta->t_prompt[i] == '\'')
				i++;
	}
	free(dta->t_prompt);
	dta->t_prompt = new;
}