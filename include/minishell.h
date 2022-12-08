/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:46:02 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/08 21:16:15 by tsorabel         ###   ########.fr       */
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
	char	*t_prompt;
	char	**prompt;
	t_list	*list_arg;
	int		exit;
}	t_data;

typedef struct s_lst
{
	char	*flag;
	char	*data;
}	t_lst;

int		get_prompt(t_data *dta);
void	ft_exit(t_data *dta);
void	redirect(t_data *dta);
int		check_equal(t_data *dta);
void	free_tab(char **str);
void	reset_data(t_data *dta);

#endif