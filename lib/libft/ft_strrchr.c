/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:41:48 by ebella            #+#    #+#             */
/*   Updated: 2024/11/11 13:25:40 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	char			*p;
	unsigned char	ch;

	i = 0;
	p = 0;
	ch = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == ch)
			p = (char *)(str + i);
		i++;
	}
	if (str[i] == ch)
		p = (char *)(str + i);
	return (p);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*str = "Heloo, world!";
	char		ch;

	ch = 'o';
	char *result = ft_strrchr(str, ch); // Recherche 'o' dans la chaîne
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
