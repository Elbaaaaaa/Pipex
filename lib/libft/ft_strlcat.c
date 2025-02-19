/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:53:06 by ebella            #+#    #+#             */
/*   Updated: 2024/11/11 14:00:35 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size <= dst_len)
		return (size + src_len);
	while (src[i] != '\0' && (dst_len + i) < (size - 1))
	{
		dest[dst_len + i] = src[i];
		i++;
	}
	dest[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
#include <stdio.h>

int	main(void)
{
	char		dest[15] = "Hello, ";
	const char	*src = "world!";
	size_t		result;

	result = ft_strlcat(dest, src, sizeof(dest));
	printf("Resulting string: %s\n", dest); // Affiche "Hello, world!"
	printf("Total length: %zu\n", result);  // Affiche la longueur totale,
	return (0);
}
*/
