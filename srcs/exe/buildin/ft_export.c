/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:00:29 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/27 17:00:41 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../../include/minishell.h"

int	valid_id(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isalnum(str[i])) && str[i] != '=' && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	export_actual(t_data *dta, char **actual, int j)
{
	char	*env_value;
	char	*var;

	if (!valid_id(actual[0]))
		mess_error(-1, "not a valid identifier", "");
	else
	{
		env_value = ft_getenv(actual[0], dta);
		if (env_value)
		{
			var = ft_strdup(actual[0]);
			unset_from_list(dta, &var, ft_strlen(var));
			ft_lstadd_back(dta->env_list,
				ft_new_node((void *) dta->actual[j],
					ft_strlen(dta->actual[j]) + 1));
			free(env_value);
			free(var);
		}
		else
		{
			ft_lstadd_back(dta->env_list,
				ft_new_node((void *) dta->actual[j],
					ft_strlen(dta->actual[j]) + 1));
		}
	}
}

void	export(t_data *dta)
{
	char	**actual;
	int		j;

	if (dta->actual[1] == NULL)
	{
		env(dta, 1);
		return ;
	}
	j = 1;
	while (dta->actual[j])
	{
		if (ft_strlen(dta->actual[j]) != 0)
		{	
			actual = ft_split(dta->actual[j], '=');
			if (actual)
				export_actual(dta, actual, j);
			free_tab(actual);
		}
		else
			mess_error(-1, "`':", " not a valid identifier");
		j++;
	}
	free_tab(dta->dup_env);
	dta->dup_env = list_to_tab(*dta->env_list);
}
