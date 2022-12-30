/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_hdoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:27:37 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/30 09:14:59 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	reconstruct_prompt(t_data *dta, int i, int j, int arg)
{
	int		k;
	char	*new;

	new = malloc(sizeof(char) * (ft_strlen(dta->prompt_t) + 2));
	while (dta->prompt_t[++i])
	{
		if (dta->prompt_t[i] == '<' && dta->prompt_t[i + 1] == '<')
		{
			k = 0;
			i += 2;
			while (is_sep(dta->prompt_t[i]) && dta->prompt_t[i])
				i++;
			while (!is_sep(dta->prompt_t[i]) && dta->prompt_t[i])
				i++;
			if (dta->keys[arg] != NULL)	
				while (dta->keys[arg][k])
					new[j++] = dta->keys[arg][k++];
			new[j++] = ' ';
			arg++;
		}
		else
			new[j++] = dta->prompt_t[i];
	}
	new[j] = '\0';
	free(dta->prompt_t);
	dta->prompt_t = ft_substr(new, 0, j);
	free(new);
}

void	store_key(t_data *dta, char *key)
{
	char	**tmp;
	int		i;

	i = -1;
	if (dta->keys == NULL)	
	{
		dta->keys = malloc(sizeof(char *) * 2);
		dta->keys[0] = key;
		dta->keys[1] = NULL;
	}
	else
	{
		while (dta->keys[++i])
		{
			if (!ft_strncmp(dta->keys[i], key, 1024))
				return ;
		}
		tmp = malloc(sizeof(char *) * (i + 2));
		i = -1;
		while (dta->keys[++i])
			tmp[i] = dta->keys[i];
		tmp[i] = key;
		tmp[i + 1] = NULL;
		if (dta->keys)
			free(dta->keys);
		dta->keys = tmp;
	}
}

void	put_str_in_new_file(const char *str, const char *key, t_data *dta)
{
	int		fd;
	char	*key_dot;

	key_dot = ft_strjoin(".", key);
	fd = open(key_dot, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("Error when opening the file");
		exit(EXIT_FAILURE);
	}
	if (str[0] != '\0' && str[0] != '\n')
		write(fd, str, ft_strlen(str));
	store_key(dta, key_dot);
	close(fd);
}

char	*get_key(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = -1;
	j = -1;
	while (is_sep(str[++j]) && str[i])
		;
	while (!is_sep(str[++i + j]) && str[i])
		;
	ret = malloc(sizeof(char) * (i + 1));
	i = -1;
	while (!is_wspace(str[++i + j]) && str[i])
		ret[i] = str[i + j];
	ret[i] = '\0';
	return (ret);
}

char	*get_prompt_hdoc(char *key)
{
	char	*tmp;
	char	*t;
	char	*ret;
	int		exit;

	exit = 0;
	ret = ft_calloc(1, 1);
	while (!exit)
	{
		tmp = readline("\x1B[32mheredoc>\x1B[37m");
		if (tmp != NULL)
		{
			if (!ft_strcmp(tmp, key))
				exit = 1;
			else
			{
				if (tmp[0] == '\0')
				{
					t = tmp;
					tmp = ft_strjoin(tmp, " ");
					free(t);
				}
				if (tmp != NULL && tmp[0] != '\0')
				{
					t = tmp;
					tmp = ft_strjoin(tmp, "\n");
					free(t);
					t = ret;
					ret = ft_strjoin(ret, tmp);
					free(t);
					free(tmp);
				}
			}
		}
	}
	if (tmp != NULL)
		free(tmp);
	return (ret);
}

void	check_is_hdoc(t_data *dta)
{
	int		i;
	char	*key;
	char	*prompt;

	i = -1;
	while (dta->prompt_t[++i])
	{
		if (dta->prompt_t[i] == '<' && dta->prompt_t[i + 1] == '<')
		{
			i += 2;
			while (is_wspace(dta->prompt_t[i]) && dta->prompt_t[i])
				i++;
			if (!is_redirect(dta->prompt_t[i]) && (ft_isalpha(dta
						->prompt_t[i]) || dta->prompt_t[i] == '_'))
			{
				key = get_key(&dta->prompt_t[i]);
				prompt = get_prompt_hdoc(key);
				put_str_in_new_file(prompt, key, dta);
				if (prompt != NULL)
					free(prompt);
				free(key);
			}
			else
			{
				mess_error(-1, "parse error near", "<<");
				dta->exit_actual = 1;
			}
		}
	}
}

// | O_APPEND