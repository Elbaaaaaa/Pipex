/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:38:46 by ebella            #+#    #+#             */
/*   Updated: 2024/11/13 19:01:56 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if ((dest == src) || n == 0)
		return (dest);
	while (n--)
		d[n] = s[n];
	d[n] = '\0';
	return (d);
}
/*
int	main(void) {
	char src[] = "Bonjour";
	char dest[20];

	// Copie les octets de src dans dest
	ft_memcpy(dest, src, strlen(src) + 1);  //
		+1 pour inclure le caractère nul '\0'

	printf("Contenu de dest : %s\n", dest);  // Affiche "Bonjour"

	return (0);
}
*/
