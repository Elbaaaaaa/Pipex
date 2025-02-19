/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:08:03 by ebella            #+#    #+#             */
/*   Updated: 2025/02/19 19:32:32 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int command_exist(t_pipex *pipex, char *command, char **envp)
{
    int     i;
    char    *tmp;

    i = 0;
    pipex->path = NULL;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
        {
            tmp = ft_strjoin(envp[i] + 5, ":");
            pipex->path = ft_split(tmp, ':');
            free(tmp);
            break ;
        }
        i++;
    }
    i = 0;
    while (pipex->path[i])
    {
        tmp = ft_strjoin(pipex->path[i], "/");
        tmp = ft_strjoin(tmp, command);
        if (access(tmp, F_OK) == 0)
        {
            free(tmp);
            return (1);
        }
        free(tmp);
        i++;
    }
    ft_putstr_fd("Error: Command not found\n", 2);
    return (0);
}

int exec_command(t_pipex *pipex, char *command, char **envp)
{
    int     i;
    char    *tmp;
    char    *full_path;

    i = 0;
    while (pipex->path[i])
    {
        tmp = ft_strjoin(pipex->path[i], "/");
        full_path = ft_strjoin(tmp, command);
        free(tmp);
        if (access(full_path, F_OK | X_OK) == 0)
        {
            execve(full_path, &command, envp);
            free(full_path);
            return (1);
        }
        free(full_path);
        i++;
    }
    ft_putstr_fd("Error: Command not found\n", 2);
    return (0);
}

void parsing(t_pipex *pipex, int argc, char **argv, char **envp)
{
    if (argc != 5)
    {
        ft_putstr_fd("Error: Wrong number of arguments\n", 2);
        exit(1);
    }
    if (access(argv[4], F_OK) == -1)
    {
        open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    }
	if (access(argv[1], F_OK) == -1)
	{
		ft_putstr_fd("Error: File 1 does not exist\n", 2);
		exit(1);
	}
	if (access(argv[4], F_OK) == -1)
	{
		ft_putstr_fd("Error: File 2 does not exist\n", 2);
		exit(1);
	}
	pipex->envp = envp;
	if (!command_exist(pipex, argv[2], envp))
		exit(1);
	if (!command_exist(pipex, argv[3], envp))
		exit(1);
}
