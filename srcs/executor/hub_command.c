/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:11:01 by lfantine          #+#    #+#             */
/*   Updated: 2022/12/13 18:01:43 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	execute_one(t_cmd *cmd, t_data *dta)
{
	if (access(cmd->cmd[0], X_OK) == -1)
	{
		mess_error("command not found: ", cmd->cmd[0]);
		exit(1);
	}
	execve(cmd->cmd[0], cmd->cmd, dta->brut_env);
	perror("Error");
	exit(1);
	return (1);
}

int	cmd_central(t_chain *chain, int pos, t_data *dta)
{
	int	in_fd;
	int	out_fd;

	if (chain->allcmd[pos]->infile != NULL)
	{
		in_fd = open(chain->allcmd[pos]->infile, O_RDONLY);
		dup2(in_fd, STDIN_FILENO);
	}
	else if (pos > 0)
		dup2(chain->fd[0], STDIN_FILENO);
	if (chain->allcmd[pos]->outfile != NULL)
	{
		out_fd = open(chain->allcmd[pos]->outfile, O_TRUNC | O_WRONLY | O_CREAT,
				0777);
		if (out_fd == -1)
		{
			perror(chain->allcmd[pos]->outfile);
			exit(1);
		}
		dup2(out_fd, STDOUT_FILENO);
	}
	else if (pos < chain->n_cmd - 1)
		dup2(chain->fd[1], STDOUT_FILENO);
	return (execute_one(chain->allcmd[pos], dta));
}
