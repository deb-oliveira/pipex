/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:32:34 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/27 15:18:23 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/childs.h"

int	child_error(char **args_exec, char *cmd)
{
	if (!args_exec[0])
	{
		ft_printf_fd(2, "pipex: %s: command not found\n", "");
		return (127);
	}
	else if (access(cmd, F_OK) == -1)
	{
		ft_printf_fd(2, "pipex: %s: command not found\n", args_exec[0]);
		return (127);
	}
	else
		perror("pipex");
	return (1);
}

void	first_child(t_pipex	pipex, char **argv, char **envp)
{
	char	**args_exec;
	char	*cmd;

	if (pipex.infile == -1)
		exit(EXIT_FAILURE);
	close(pipex.fd[0]);
	dup2(pipex.fd[1], STDOUT_FILENO);
	dup2(pipex.infile, STDIN_FILENO);
	args_exec = ft_split2(argv[2], " ", "'");
	cmd = ft_strjoin("/usr/bin/", args_exec[0]);
	execve(cmd, args_exec, envp);
	exit(child_error(args_exec, cmd));
}

void	second_child(t_pipex	pipex, char **argv, char **envp)
{
	char	**args_exec;
	char	*cmd;

	if (pipex.outfile == -1)
		exit(EXIT_FAILURE);
	close(pipex.fd[1]);
	dup2(pipex.outfile, STDOUT_FILENO);
	dup2(pipex.fd[0], STDIN_FILENO);
	args_exec = ft_split2(argv[3], " ", "'");
	cmd = ft_strjoin("/usr/bin/", args_exec[0]);
	execve(cmd, args_exec, envp);
	exit(child_error(args_exec, cmd));
}
