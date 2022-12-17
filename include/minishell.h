/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:46:02 by tsorabel          #+#    #+#             */
/*   Updated: 2022/12/17 16:03:50 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define USER "\033[0;36mminishell$> \033[0;37m"
# define MAXINT 2147483647

# include"../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>
# include <errno.h>
# include <fcntl.h>
# include <termios.h>

typedef struct s_lst
{
	char	*flag;
	char	*data;
}	t_lst;

typedef struct s_data
{
	char	*nickname;
	char	*empty;
	t_lst	**d_arg;
	size_t	nb_arg;
	char	*prompt_t;
	int		secure_len;
	char	*temp_str_replace_arg;
	char	**prompt;
	char	***p;
	int		nb_cmd_p;
	char	**historique;
	size_t	nb_arg_hist;
	size_t	nb_pipe;
	int		exit_multi_pipe;
	char	*pipe_str;
	char	**env;
	char	**brut_env;
	int		exit;
	int		exit_actual;
}	t_data;

typedef struct s_cmd
{
	char	*infile;
	char	*outfile;
	char	*path;
	char	**cmd;
}	t_cmd;

typedef struct s_chain
{
	int		fd[2];
	t_cmd	**allcmd;
	int		pos;
	int		n_cmd;
}	t_chain;

//prompt
void	init_dta(t_data *dta, char **env, int argc, char **argv);
int		geprompt_t(t_data *dta);
void	get_nickname(t_data *dta, char **env);
void	print_char_tab_t(char **tab);
void	rl_replace_line(const char *text, int clear_undo);
void	init_triple(t_data *dta);
void	print_t_tab(char ***tab);

//pars
int		is_wspace(char c);
int		is_sep(char c);
int		is_to_space(char c);
void	space_spe_char(t_data *dta);
size_t	nb_charinstr(char *str, char c);
int		check_equal(t_data *dta);
void	check_end_pipe(t_data *dta);
int		check_last_char(char *str, char c);
int		check_only_space(t_data *dta);
void	replace_pipe(t_data *dta);
void	replace_arg(t_data *dta);
void	replace_in_quote(t_data *dta);
void	replace_in_simple_quote(t_data *dta);
void	replace_special_char(t_data *dta);
void	replace_special_char_in_arg(t_data *dta);
void	replace_not_in_db(t_data *dta);
void	replace_existing_arg(t_data *dta);
void	remove_quote(t_data *dta);
void	replace_tab(t_data *dta);
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
void	print_error(char *err_type, char *err);
void	free_tab(char **str);
void	free_triple_tab(char ***tab);
void	free_lst(t_lst **lst, t_data *dta);
void	free_tab_len(char **str, size_t nb_arg);
void	reset_data(t_data *dta);
void	check_err(t_data *dta);

//signal
void	init_signal(t_data *dta, struct sigaction *sa,
			struct termios *terminal);
void	handle_sig(int signum, siginfo_t *info, void *ptr);

//executor
int		hub_exec(t_data *dta);
int		make_chains(t_chain *chain, t_data *dta);
int		make_allcmd(t_chain *chain, t_data *dta);
char	*replace_cmd_path(char *old_p, t_data *dta);
void	print_tab(t_cmd *cmd);
void	free_allcmd(t_chain *chain);
int		change_command(t_chain *chain, int i, int len, int j);
void	printf_state(t_chain *chain);
int		cmd_central(t_chain *chain, int pos, t_data *dta);
int		ret_p_error(void);
int		mess_error(char *s1, char *s2);

#endif