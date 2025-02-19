/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:13:13 by ebella            #+#    #+#             */
/*   Updated: 2025/02/19 19:56:14 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <../lib/libft/libft.h>

typedef struct s_pipex
{
    char    **envp;
    char    **path;
    int     fd[2];
    int     pid;
    int     status;
	int		infile;
	int		outfile;
}   t_pipex;

int     main(int argc, char **argv, char **envp);
int     command_exist(t_pipex *pipex, char *command, char **envp);
int     exec_command(t_pipex *pipex, char *command, char **envp);
void    parsing(t_pipex *pipex, int argc, char **argv, char **envp);

#endif