/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:33:01 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/27 15:16:30 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHILDS_H
# define CHILDS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../.dependencies/printf/ft_printf.h"
# include "utils.h"
# include "structures.h"

void	second_child(t_pipex	pipex, char **argv, char **envp);

void	first_child(t_pipex	pipex, char **argv, char **envp);

int		child_error(char **args_exec, char *cmd);

#endif