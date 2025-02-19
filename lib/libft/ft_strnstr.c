/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:46:30 by ebella            #+#    #+#             */
/*   Updated: 2024/11/14 16:48:55 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;
	size_t	needle_len;

	i = 0;
	hay = (char *)haystack;
	needle_len = ft_strlen(needle);
	if (haystack == needle || needle_len == 0)
		return (hay);
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (i + j < len && hay[i + j] != '\0' && needle[j] != '\0' && hay[i
				+ j] == needle[j])
			j++;
		if (j == needle_len)
			return (hay + i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*str = "Hello, World!";
	const char	*sub = "World";
	char		*result;

	// Limite la recherche aux 10 premiers caractères
	result = ft_strnstr(str, sub, 14);
	if (result)
	{
		printf("Sous-chaîne trouvée : %s\n", result);
	}
	else
	{
		printf("Sous-chaîne non trouvée.\n");
	}
	return (0);
}
*/
