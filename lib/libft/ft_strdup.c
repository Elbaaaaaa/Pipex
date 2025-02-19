/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:07:23 by ebella            #+#    #+#             */
/*   Updated: 2024/11/13 19:03:11 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ch;
	size_t	len;

	len = ft_strlen(s);
	ch = malloc(ft_strlen(s) + 1);
	if (!ch)
		return (NULL);
	ft_strlcpy(ch, s, len + 1);
	return (ch);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	*original = "Hello, World!";
	char		*copy;

	// Duplication de la chaîne
	copy = ft_strdup(original);
	if (copy == NULL)
	{
		printf("Échec de l'allocation de mémoire\n");
		return (1);
	}
	printf("Chaîne originale : %s\n", original);
	printf("Copie de la chaîne : %s\n", copy);
	// Libération de la mémoire allouée pour la copie
	free(copy);
	return (0);
}
*/
