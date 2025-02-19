/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:42:09 by ebella            #+#    #+#             */
/*   Updated: 2024/11/13 19:04:29 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char buffer[11] = "ABCDEFGHIJ"; // 10 caractères + le '\0'
	printf("Avant memmove : %s\n", buffer);
	// Déplacement de "ABCDE" dans la position suivante (buffer + 5)
	ft_memmove(buffer + 5, buffer, 5);
	// Chevauchement car src et dest se croisent
	printf("Après memmove : %s\n", buffer); // Affiche "ABCDEABCDE"
	return (0);
}
*/
