/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:18:01 by ebella            #+#    #+#             */
/*   Updated: 2024/11/11 13:23:59 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i++;
	}
	if (ch == '\0')
		return ((char *)str + i);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*str = "Heloo, world!";
	char		ch;

	ch = 'o';
	char *result = ft_strchr(str, ch); // Recherche 'o' dans la chaîne
	if (result)
	{
		printf("Found '%c' at position: %ld\n", ch, result - str);
	}
	else
	{
		printf("Character not found\n");
	}
	return (0);
}
*/
