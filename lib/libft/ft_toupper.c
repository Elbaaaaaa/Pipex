/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:21:55 by ebella            #+#    #+#             */
/*   Updated: 2024/11/08 16:42:00 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -= 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	c;

	c = 'a';
	char result = ft_toupper(c);       // Convertit 'a' en 'A'
	printf("Uppercase: %c\n", result); // Affiche 'A'
	c = 'Z';
	result = ft_toupper(c);            // Ne modifie pas 'Z'
	printf("Uppercase: %c\n", result); // Affiche 'Z'
	return (0);
}
*/
