/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:00:29 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/27 17:01:14 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../../include/minishell.h"

void	update_env_var(t_data *dta, char *var, char *value)
{
	char	**actual_in;
	char	*tempo;

	actual_in = NULL;
	if (dta->actual)
		actual_in = tab_dup(dta->actual);
	tempo = ft_strjoin(var, value);
	if (dta->actual)
		free_tab(dta->actual);
	dta->actual = malloc(sizeof(char *) * 3);
	dta->actual[0] = ft_strdup("export");
	dta->actual[1] = tempo;
	dta->actual[2] = NULL;
	export(dta);
	free_tab(dta->actual);
	dta->actual = NULL;
	dta->actual = actual_in;
}

void	cd_actual(t_data *dta, char **pwd, char **home_path)
{
	if (*pwd)
		update_env_var(dta, "OLDPWD=", *pwd);
	else
	{
		update_env_var(dta, "OLDPWD=", "");
		if (errno)
		{	
			chdir("/");
			*pwd = getcwd(NULL, 0);
		}	
	}
	free(*pwd);
	*pwd = getcwd(NULL, 0);
	update_env_var(dta, "PWD=", *pwd);
	free(*home_path);
	free(*pwd);
}

void	cd(t_data *dta)
{
	char	*home_path;
	char	*pwd;

	home_path = ft_getenv("HOME", dta);
	pwd = getcwd(NULL, 0);
	if (!dta->actual[1] || !(ft_strncmp(dta->actual[1], "", 2)))
	{
		if (chdir(home_path) == -1)
			mess_error(-1, "HOME not set", "");
	}
	else if (chdir(dta->actual[1]) == -1)
	{
		if (errno == EACCES)
			mess_error(1, "Permission denied", "");
		if (errno == ENAMETOOLONG)
			mess_error(-1, "File name too long", "");
		else
			mess_error(1, "No such file or directory", "");
	}
	cd_actual(dta, &pwd, &home_path);
}
