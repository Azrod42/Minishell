/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:23:03 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/08 10:45:05 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	get_prompt(t_data *dta)
{
	char	*prompt;

	prompt = readline(USER);
	dta->prompt = ft_split(prompt, ' ');
	free(prompt);
	return (0);
}
