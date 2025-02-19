/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:29:20 by ebella            #+#    #+#             */
/*   Updated: 2024/11/08 15:49:59 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void) {
	char data1[] = "Hello, Wordl!";
	char data2[] = "Hello, World!";
	char data3[] = "Hello, C!";

	// Comparer data1 et data2
	if (ft_memcmp(data1, data2, sizeof(data1)) == 0) {
		printf("data1 et data2 sont identiques.\n");
	} else {
		printf("data1 et data2 sont différents.\n");
	}

	// Comparer data1 et data3
	if (ft_memcmp(data1, data3, sizeof(data1)) == 0) {
		printf("data1 et data3 sont identiques.\n");
	} else {
		printf("data1 et data3 sont différents.\n");
	}

	return (0);
}
*/
