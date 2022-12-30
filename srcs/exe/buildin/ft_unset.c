/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:00:29 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/30 14:24:53 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../../include/minishell.h"

void	delete_head(t_data *dta)
{
	t_list	*tempo;

	tempo = *dta->env_list;
	*dta->env_list = (*dta->env_list)->next;
	ft_lstdelone(tempo, free);
}

void	unset_from_list(t_data *dta, char **var, int size_var)
{
	t_list	*actual;
	t_list	*tempo;
	char	*str;

	actual = *dta->env_list;
	str = (char *)actual->content;
	if (!(ft_strncmp((*var), str, size_var)) && str[size_var] == '=')
		delete_head(dta);
	else
	{
		while (actual)
		{
			if (actual->next != NULL)
				str = (char *)actual->next->content;
			if (!(ft_strncmp((*var), str, size_var)) && str[size_var] == '=')
			{
				tempo = actual->next;
				actual->next = actual->next->next;
				ft_lstdelone(tempo, free);
				break ;
			}
			actual = actual->next;
		}
	}
}

int	is_valid_id(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isalnum(str[i])) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	unset_actual2(t_data *dta, char *var)
{
	int		size_var;

	size_var = ft_strlen(var);
	unset_from_list(dta, &var, size_var);
	if (!(ft_strncmp(var, "PATH=", size_var)))
		dta->path_ok = 1;
	free_tab(dta->dup_env);
	dta->dup_env = list_to_tab(*dta->env_list);
}

void	unset(t_data *dta, int j)
{
	char	*var;
	char	*tempo_env;

	if (dta->actual[1] == NULL)
		return ;
	while (dta->actual[j])
	{
		if (!is_valid_id(dta->actual[j]))
			mess_error(dta, -1, "not a valid identifier", "");
		else
		{
			var = ft_strdup(dta->actual[j]);
			tempo_env = ft_getenv(var, dta);
			if (tempo_env)
			{
				unset_actual2(dta, var);
				free(tempo_env);
			}
			free(var);
		}
		j++;
	}
}
