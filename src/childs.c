/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:32:34 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/06 17:55:33 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/childs.h"

void	child_error(char **args_exec, char *cmd)
{
	if (!args_exec[0])
		ft_printf_fd(2, "pipex: %s: command not found\n", "");
	else if (access(cmd, F_OK) == -1)
		ft_printf_fd(2, "pipex: %s: command not found\n", args_exec[0]);
	else
		perror("pipex");
}

void	first_child(t_pipex	pipex, char **argv)
{
	char	**args_exec;
	char	*cmd;

	close(pipex.fd[0]);
	args_exec = ft_split2(argv[2], " ", "'");
	dup2(pipex.infile, STDIN_FILENO);
	dup2(pipex.fd[1], STDOUT_FILENO);
	cmd = ft_strjoin("/usr/bin/", args_exec[0]);
	execve(cmd, args_exec, NULL);
	child_error(args_exec, cmd);
	exit(EXIT_FAILURE);
}

void	second_child(t_pipex	pipex, char **argv)
{
	char	**args_exec;
	char	*cmd;

	close(pipex.fd[1]);
	args_exec = ft_split2(argv[3], " ", "'");
	dup2(pipex.outfile, STDOUT_FILENO);
	dup2(pipex.fd[0], STDIN_FILENO);
	cmd = ft_strjoin("/usr/bin/", args_exec[0]);
	execve(cmd, args_exec, NULL);
	child_error(args_exec, cmd);
	exit(EXIT_FAILURE);
}
