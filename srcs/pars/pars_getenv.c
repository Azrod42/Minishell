/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_getenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:00:29 by tsorabel          #+#    #+#             */
/*   Updated: 2023/01/05 08:53:11 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

char	*ft_getenv_aux(t_list *aux, char **var, int len)
{
	int	total_size;

	while (aux)
	{
		len = ft_strlen(*var);
		total_size = ft_strlen(aux->content);
		if (!(ft_strncmp(*var, aux->content, len)))
		{
			free(*var);
			return (ft_substr(aux->content, len, total_size - len));
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
	int		len;

	aux = *dta->env_list;
	var = NULL;
	while (aux)
	{
		len = ft_strlen(str);
		if (!(ft_strncmp(str, aux->content, len))
			&& ((char *)aux->content)[len] == '\0')
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
	return (ft_getenv_aux(aux, &var, len));
}
