/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:46:02 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/13 16:33:00 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define USER "\033[0;36mminichibre$> \033[0;37m"
# define MAXI 2147483647

# include"../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
//# include <readline/history.h>

typedef struct s_lst
{
	char	*flag;
	char	*data;
}	t_lst;

typedef struct s_data
{
	t_lst	**d_arg;
	size_t	nb_arg;
	char	*prompt_t;
	char	*temp_str_replace_arg;
	char	**prompt;
	char	**historique;
	size_t	nb_arg_hist;
	size_t	nb_pipe;
	int		exit_multi_pipe;
	char	*pipe_str;
	char	**env;
	int		exit;
	int		exit_actual;
}	t_data;

typedef struct s_cmd
{
	char	*path;
	char	**cmd;
}	t_cmd;

typedef struct s_chain
{
	char	*infile;
	char	*outfile;
	int		fd[2];
	t_cmd	**allcmd;
	int		pos;
}	t_chain;

//prompt
int		geprompt_t(t_data *dta);

//pars
int		is_wspace(char c);
int		is_sep(char c);
size_t	nb_charinstr(char *str, char c);
int		check_equal(t_data *dta);
void	check_end_pipe(t_data *dta);
void	replace_pipe(t_data *dta);
void	replace_arg(t_data *dta);
void	replace_in_quote(t_data *dta);
void	replace_in_simple_quote(t_data *dta);
void	replace_special_char(t_data *dta);
void	replace_not_in_db(t_data *dta);
void	replace_existing_arg(t_data *dta);
void	remove_quote(t_data *dta);
void	add_historic(t_data *dta);
void	print_historic(t_data *dta);
void	print_arg(t_data *dta);
t_lst	**pars_equal(t_data *dta);
void	redirect(t_data *dta);
char	*ft_strnstr_len(const char *big, const char *little, size_t len);
char	*strstr_el(const char *big, const char *little,
			size_t len, size_t ilen);
int		hub_env(t_data *dta, char **env_brut);

//exit
void	ft_exit(t_data *dta);
void	free_tab(char **str);
void	reset_data(t_data *dta);
void	check_err(t_data *dta);

//executor
int		hub_exec(t_data *dta);
int		make_chains(t_chain *chain, t_data *dta);
int		make_allcmd(t_chain *chain, t_data *dta);
char	*replace_cmd_path(char *old_p, t_data *dta);
void	print_tab(t_cmd *cmd);
void	free_allcmd(t_chain *chain);

#endif