/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_hdoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:27:37 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/30 14:28:08 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

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

char	*get_primpt_hodc_2(char *tmp)
{
	char	*t;

	if (tmp[0] == '\0')
	{
		t = tmp;
		tmp = ft_strjoin(tmp, " ");
		free(t);
	}
	return (tmp);
}

char	*get_primpt_hodc_3(char *tmp, char *ret)
{
	char	*t;

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
	return (ret);
}

char	*get_prompt_hdoc(char *key)
{
	char	*tmp;
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
				tmp = get_primpt_hodc_2(tmp);
				ret = get_primpt_hodc_3(tmp, ret);
			}
		}
	}
	if (tmp != NULL)
		free(tmp);
	return (ret);
}

void	check_is_hdoc(t_data *dta, int i)
{
	char	*key;
	char	*prompt;

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
			}
			else
			{
				mess_error(dta, -1, "parse error near", "<<");
				dta->exit_actual = 1;
			}
		}
	}
}

// | O_APPEND