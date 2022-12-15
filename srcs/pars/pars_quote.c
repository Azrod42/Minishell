/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:31:22 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/13 20:04:19 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	replace_in_quote(t_data *dta)
{
	int	nbquote;
	int	i;

	nbquote = nb_charinstr(dta->prompt_t, '\"');
	if (nbquote == 0)
		return ;
	i = -1;
	while (dta->prompt_t[++i] && nbquote > 1)
	{
		while (dta->prompt_t[i] != '\"'
			&& dta->prompt_t[i] && dta->prompt_t[i] != '\'')
			i++;
		if (dta->prompt_t[i] == '\'')
		{
			while (dta->prompt_t[++i] != '\'')
				if (dta->prompt_t[i] == '\"')
					nbquote--;
		}	
		else
			while (dta->prompt_t[++i] != '\"' && dta->prompt_t[i])
				if (is_sep(dta->prompt_t[i]) || dta->prompt_t[i] == '\'')
					dta->prompt_t[i] = dta->prompt_t[i] * -1;
		nbquote -= 2;
	}
}

size_t	get_len_remove_quote(t_data *dta)
{
	size_t	i;
	size_t	trm;

	i = -1;
	trm = 0;
	while (dta->prompt_t[++i])
	{
		if (dta->prompt_t[i] == '\'')
		{
			while (dta->prompt_t[++i] != '\'' && dta->prompt_t[i])
				;
			if (dta->prompt_t[i] == '\'')
				trm += 2;
			i++;
		}
		else if (dta->prompt_t[i] == '\"')
		{
			while (dta->prompt_t[++i] != '\"' && dta->prompt_t[i])
				;
			if (dta->prompt_t[i] == '\"')
				trm += 2;
			i++;
		}
	}
	return (trm);
}

void	remove_quote(t_data *dta)
{
	int		i;
	int		k;
	char	*new;

	i = -1;
	k = 0;
	new = malloc(sizeof(char) * (ft_strlen(dta->prompt_t)
				- get_len_remove_quote(dta)));
	while (dta->prompt_t[++i])
	{
		if (dta->prompt_t[i] == '\'')
			while (dta->prompt_t[++i] != '\'' && dta->prompt_t[i])
				new[k++] = dta->prompt_t[i];
		else if (dta->prompt_t[i] == '\"')
			while (dta->prompt_t[++i] != '\"' && dta->prompt_t[i])
				new[k++] = dta->prompt_t[i];
		if (dta->prompt_t[i] == '\'' || dta->prompt_t[i] == '\"')
			i++;
		new[k++] = dta->prompt_t[i];
	}
	new[k] = '\0';
	free(dta->prompt_t);
	dta->prompt_t = new;
}
