/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:32:12 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/27 15:21:24 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_files(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

int	pipex_init(int argc, char **argv, t_pipex *pipex)
{
	if (argc != 5)
	{
		ft_printf("Input error: not enough arguments\n");
		return (-4);
	}
	if (pipe(pipex->fd) == -1)
	{
		perror("");
		return (-3);
	}
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->outfile < 0)
	{
		perror(argv[argc - 1]);
	}
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		perror(argv[1]);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	if (pipex_init(argc, argv, &pipex) < -2)
		return (EXIT_FAILURE);
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
	{
		perror("");
		return (-4);
	}
	if (pipex.pid1 == 0)
		first_child(pipex, argv, envp);
	waitpid(pipex.pid1, NULL, 0);
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
	{
		perror("");
		return (-5);
	}
	if (pipex.pid2 == 0)
		second_child(pipex, argv, envp);
	close_files(&pipex);
	waitpid(pipex.pid2, &status, 0);
	exit(WEXITSTATUS(status));
}
