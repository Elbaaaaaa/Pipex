/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:54:12 by ebella            #+#    #+#             */
/*   Updated: 2024/11/08 11:10:38 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*t;

	t = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		t[i] = (char)c;
		i++;
	}
	return ((unsigned char *)s);
}

/*int main ()
{
  int arr[10];
  memset(arr, 0, 5);
  ft_memset(arr, 0, 5);
for (int i = 0; i < 10; i++)
  {
	printf("%d", arr[i]);
	pri
  }
		return (0);
}*/
