/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:00:29 by tsorabel          #+#    #+#             */
/*   Updated: 2023/01/05 12:55:11 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	mess_error(t_data *dta, int err, char *s1, char *s2)
{
	if (dta->exit_actual != 0)
		return (0);
	if (g_exit_status == 130)
		return (0);
	if (err != -1)
		g_exit_status = err;
	else
		g_exit_status = 1;
	printf("\033[0;31m Error: %s \033[0;33m%s\n\033[0;37m", s1, s2);
	dta->exit_actual = 1;
	return (0);
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

char	**tab_dup(char **tab)
{
	char	**out;
	int		size;
	int		i;

	i = 0;
	size = tab_len(tab);
	out = malloc(sizeof(char *) * (size + 1));
	if (!out)
		return (NULL);
	while (tab[i])
	{
		out[i] = ft_strdup(tab[i]);
		if (!out[i])
		{
			free_tab(out);
			return (NULL);
		}
		i++;
	}
	out[i] = NULL;
	return (out);
}

int	is_redirect(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

void	init_env_list(t_data *dta, t_list **envp, char **env)
{
	int		i;
	int		size;

	size = 0;
	i = 0;
	dup_env(dta, env);
	while (dta->dup_env[i] != NULL)
	{
		size = ft_strlen(dta->dup_env[i]);
		ft_lstadd_back(envp, ft_new_node((void *) dta->dup_env[i], size + 1));
		i++;
	}
	dta->env_list = envp;
}
