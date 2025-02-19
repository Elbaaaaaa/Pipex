/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:41:54 by ebella            #+#    #+#             */
/*   Updated: 2024/11/08 10:53:46 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*l;
	unsigned char	r;
	size_t			i;

	l = (unsigned char *)s;
	r = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (l[i] == r)
			return ((void *)&l[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	data[] = "Hello, World!";
	char	*result;

	// Rechercher le caractère 'o' dans les 10 premiers octets
	result = ft_memchr(data, 'o', 10);
	if (result != NULL)
	{
		printf("Caractère trouvé à l'adresse : %p\n", (void *)result);
		printf("Caractère trouvé : %c\n", *result); // Affiche "o"
	}
	else
	{
		printf("Caractère non trouvé dans les 10 premiers octets.\n");
	}
	return (0);
}
*/
