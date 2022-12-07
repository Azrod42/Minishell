/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:46:02 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/07 18:45:14 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define USER "tsorabel$> "

# include"../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_data
{
	char	**prompt;
	int		exit;
}	t_data;

int		get_prompt(t_data *dta);
void	ft_exit(t_data *dta);
void	redirect(t_data *dta);

#endif