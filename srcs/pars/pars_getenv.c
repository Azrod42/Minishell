/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_getenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:00:29 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/27 17:06:01 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

char	*ft_getenv_aux(t_list *aux, char **var, int size_var)
{
	int	total_size;

	while (aux)
	{
		size_var = ft_strlen(*var);
		total_size = ft_strlen(aux->content);
		if (!(ft_strncmp(*var, aux->content, size_var)))
		{
			free(*var);
			return (ft_substr(aux->content, size_var, total_size - size_var));
		}
		aux = aux->next;
	}
	free(*var);
	return (NULL);
}

char	*ft_getenv(const char *str, t_data *dta)
{
	t_list	*aux;
	char	*var;
	int		size_var;

	aux = *dta->env_list;
	var = NULL;
	while (aux)
	{
		size_var = ft_strlen(str);
		if (!(ft_strncmp(str, aux->content, size_var))
			&& ((char *)aux->content)[size_var] == '\0')
		{
			var = ft_strdup(aux->content);
			free(aux->content);
			aux->content = ft_strjoin(var, "=");
			free(var);
			return (ft_getenv(str, dta));
		}
		aux = aux->next;
	}
	aux = *dta->env_list;
	var = ft_strjoin(str, "=");
	return (ft_getenv_aux(aux, &var, size_var));
}
