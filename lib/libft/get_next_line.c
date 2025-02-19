/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:21:27 by ebella            #+#    #+#             */
/*   Updated: 2024/12/05 17:13:37 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_free concatenates buffer with ret and frees both
char	*ft_free(char *buffer, char *ret)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, ret);
	free(buffer);
	return (tmp);
}

// read_line reads the file and returns the content
char	*read_line(int fd, char *ret)
{
	char	*buffer;
	int		readed;

	if (!ret)
		ret = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = 0;
		ret = ft_free(ret, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (ret);
}

char	*ft_next_line(char *buffer)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	free(buffer);
	return (next);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_line(stash);
	stash = ft_next_line(stash);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(int ac, char **av)
// {
// 	int i = 0;
// 	char *line;
// 	if (ac == 2)
// 	{
// 		int fd = open("test.txt", O_RDONLY);
// 		while (i < atoi(av[1]))
// 		{
// 			line = get_next_line(fd);
// 			printf("%d: %s", i, line);
// 			free(line);
// 			i++;
// 		}
// 		while ((line = get_next_line(fd)) != NULL)
// 			free(line);
// 		close(fd);
// 	}
// 	return (0);
// }