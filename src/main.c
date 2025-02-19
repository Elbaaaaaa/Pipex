/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:12:57 by ebella            #+#    #+#             */
/*   Updated: 2025/02/19 19:21:40 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, char **argv, char **envp)
{
    t_pipex pipex;

    parsing(&pipex, argc, argv, envp);
    if (pipe(pipex.fd) == -1)
    {
        ft_putstr_fd("Error: Pipe failed\n", 2);
        exit(1);
    }
    pipex.pid = fork();
    if (pipex.pid == -1)
    {
        ft_putstr_fd("Error: Fork failed\n", 2);
        exit(1);
    }
    if (pipex.pid == 0)
    {
        close(pipex.fd[0]);
        dup2(pipex.fd[1], 1);
        close(pipex.fd[1]);
        exec_command(&pipex, argv[2], envp);
    }
    else
    {
        waitpid(pipex.pid, &pipex.status, 0);
        pipex.pid = fork();
        if (pipex.pid == -1)
        {
            ft_putstr_fd("Error: Fork failed\n", 2);
            exit(1);
        }
        if (pipex.pid == 0)
        {
            close(pipex.fd[1]);
            dup2(pipex.fd[0], 0);
            close(pipex.fd[0]);
            exec_command(&pipex, argv[3], envp);
        }
        else
        {
            waitpid(pipex.pid, &pipex.status, 0);
            close(pipex.fd[0]);
            close(pipex.fd[1]);
        }
    }
    return (0);
}

