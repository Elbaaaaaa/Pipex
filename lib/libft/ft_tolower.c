/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:02:56 by ebella            #+#    #+#             */
/*   Updated: 2024/11/08 17:10:42 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c += 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	c;

	c = 'A';
	char result = ft_tolower(c);       // Convertit 'a' en 'A'
	printf("lowercase: %c\n", result); // Affiche 'A'
	c = 'a';
	result = ft_tolower(c);            // Ne modifie pas 'Z'
	printf("lowercase: %c\n", result); // Affiche 'Z'
	return (0);
}
*/
