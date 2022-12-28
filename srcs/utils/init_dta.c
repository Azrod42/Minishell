/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:33:01 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/28 22:50:50 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	init_dta(t_data *dta, char **env, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	dta->exit = 0;
	dta->nb_arg = 0;
	dta->status = 0;
	dta->actual = NULL;
	dta->nb_arg_hist = 0;
	dta->path_ok = 0;
	dta->pipe_str = ft_strdup("init");
	dta->empty = ft_strdup("E");
	dta->empty[0] = dta->empty[0] * -1;
	if (hub_env(dta, env) == -1)
		exit(1);
	get_nickname(dta, env);
	g_exit_status = 0;
	dta->prompt_t = ft_strdup("defaultminishell=defaultminishell");
	dta->d_arg = pars_equal(dta);
	free(dta->prompt_t);
}

void	init_basic_env(t_data *dta, char **pwd)
{
	dta->dup_env = malloc(sizeof(char *) * 5);
	dta->dup_env[0]
		= ft_strdup("PATH=/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
	dta->dup_env[1] = ft_strjoin("PWD=", (*pwd));
	dta->dup_env[2] = ft_strdup("SHLVL=0");
	dta->dup_env[3] = ft_strdup("_=./minishell");
	dta->dup_env[4] = NULL;
}

void	dup_env(t_data *dta, char **env)
{
	int		i;
	char	*pwd;

	i = 0;
	dta->dup_env = NULL;
	pwd = getcwd(NULL, 0);
	if (!(*env))
		init_basic_env(dta, &pwd);
	else
	{
		while (env[i] != NULL)
			i++;
		dta->dup_env = malloc(sizeof(char *) * (i + 1));
		i = 0;
		while (env[i])
		{
			dta->dup_env[i] = ft_strdup(env[i]);
			i++;
		}
		dta->dup_env[i] = NULL;
	}
	free(pwd);
}

int	size_to_char(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i] != c && str[i])
		;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

void	put_env_in_arg(t_data *dta,  char **env)
{
	int		i;
	t_lst	*new;

	i = -1;
	while (env[++i])
	{
		new = malloc(sizeof(t_lst) * 1);
		if (size_to_char(env[i], '=') != -1)
			new->flag = malloc(sizeof(char) * (size_to_char(env[i], '=') + 1));
		ft_strlcpy(new->flag, env[i], size_to_char(env[i], '=') + 1);
		new->flag[size_to_char(env[i], '=')] = '\0';
		new->data = ft_strdup(&env[i][size_to_char(env[i], '=') + 1]);
		addtab_arg(dta, new);
	}
}
