/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:12:57 by ebella            #+#    #+#             */
/*   Updated: 2025/02/19 20:04:10 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;

	if (argc != 5)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		return (1);
	}
	parsing(&pipex, argc, argv, envp);
	if (pipe(pipex.fd) == -1)
	{
		ft_putstr_fd("Error: Pipe failed\n", 2);
		return (1);
	}
	pipex.pid = fork();
	if (pipex.pid == -1)
	{
		ft_putstr_fd("Error: Fork failed\n", 2);
		return (1);
	}
	if (pipex.pid == 0)
	{
		dup2(pipex.fd[1], 1);
		close(pipex.fd[0]);
		close(pipex.fd[1]);
		exec_command(&pipex, pipex.cmd1, envp);
	}
	else
	{
		waitpid(pipex.pid, &pipex.status, 0);
		dup2(pipex.fd[0], 0);
		close(pipex.fd[0]);
		close(pipex.fd[1]);
		exec_command(&pipex, pipex.cmd2, envp);
	}
	return (0);
}

