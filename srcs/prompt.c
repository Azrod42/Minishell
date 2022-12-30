/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:23:03 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/30 17:45:40 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	check_only_space(t_data *dta)
{
	size_t	i;

	i = -1;
	while (dta->prompt_t[++i])
		if (!is_sep(dta->prompt_t[i]))
			return (1);
	return (0);
}

int	get_prompt_t(t_data *dta)
{
	dta->exit_actual = 0;
	dta->prompt_t = readline(dta->nickname);
	if (dta->prompt_t == NULL)
		ft_exit(dta);
	dta->prompt_t[ft_strlen(dta->prompt_t)] = '\0';
	replace_tab(dta);
	if (dta->prompt_t[0] && check_only_space(dta))
		add_historic(dta);
	space_spe_char(dta);
	check_is_hdoc(dta, -1);
	if (dta->keys != NULL && dta->exit_actual == 0)
		reconstruct_prompt(dta, -1, 0);
	check_end_pipe(dta);
	if (nb_charinstr(dta->prompt_t, '|') != 0)
		replace_pipe(dta);
	if (nb_charinstr(dta->prompt_t, '|') != 0)
		space_spe_char(dta);
	if (dta->exit_actual == 0)
		check_is_hdoc(dta, -1);
	if (dta->keys != NULL && dta->exit_actual == 0
		&& nb_charinstr(dta->prompt_t, '|') != 0)
		reconstruct_prompt(dta, -1, 0);
	if (geprompt_2(dta) == 1)
		return (1);
	return (0);
}

int	geprompt_2(t_data *dta)
{
	replace_in_quote(dta);
	replace_in_simple_quote(dta);
	if (nb_charinstr(dta->prompt_t, '\"') != 0
		|| nb_charinstr(dta->prompt_t, '\'') != 0)
		remove_quote(dta);
	if (check_equal(dta))
		dta->d_arg = pars_equal(dta);
	replace_existing_arg(dta);
	replace_not_in_db(dta, 0);
	replace_arg(dta);
	if (!check_only_space(dta))
		dta->prompt_t[0] = '\0';
	if (dta->prompt_t[0] == '\0')
	{
		dta->prompt = NULL;
		return (1);
	}
	dta->prompt = ft_split(dta->prompt_t, ' ');
	replace_special_char(dta);
	return (0);
}

// int i = 0;
// printf("DEBUG[%02d]: %s\n", i += 1, dta->prompt_t);

	//print_historic(dta);
	//replace_special_char_in_arg(dta);