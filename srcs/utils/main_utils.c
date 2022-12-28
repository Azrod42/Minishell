/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/27 18:35:54 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	check_path2(t_data *dta)
{
	char	*aux;

	aux = ft_getenv("PWD", dta);
	if (!aux)
	{
		aux = getcwd(NULL, 0);
		update_env_var(dta, "PWD=", aux);
		free(aux);
	}
	else
		free(aux);
	aux = ft_getenv("_", dta);
	if (!aux)
		update_env_var(dta, "_=", "env");
	else
		free(aux);
}

void	check_path(t_data *dta)
{
	char	*aux;

	aux = ft_getenv("PATH", dta);
	if (!aux)
		update_env_var(dta, "PATH=",
			"/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
	else
		free(aux);
	aux = ft_getenv("SHLVL", dta);
	if (!aux)
		update_env_var(dta, "SHLVL=", "0");
	else
		free(aux);
	check_path2(dta);
}

void	update_shlvl(t_data *dta)
{
	int		lvl;
	char	*number;
	char	*aux;	

	aux = ft_getenv("SHLVL", dta);
	lvl = ft_atoi(aux);
	if (lvl < 0)
	{
		ft_putstr_fd("minishell:", 2);
		if (lvl == -1)
			lvl++;
		ft_putendl_fd("warning: shell lvl too high, resetting to 1", 2);
	}
	free(aux);
	lvl++;
	number = ft_itoa(lvl);
	update_env_var(dta, "SHLVL=", number);
	free(number);
}
