/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:45:30 by ebella            #+#    #+#             */
/*   Updated: 2024/11/13 18:51:20 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

char	*ft_dup(char *str, char c)
{
	int		i;
	char	*dup;
	int		len;

	len = 0;
	while (str[len] != c && str[len])
		len++;
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
	{
		free(dup);
		return (NULL);
	}
	i = 0;
	while (str[i] && str[i] != c)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**split(char *str, char c)
{
	char	**tab;

	tab = malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!tab)
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	*str;
	char	**tab;

	i = 0;
	str = (char *)s;
	tab = split(str, c);
	if (!str || !tab)
		return (NULL);
	while (*str)
	{
		while (*str == c && str)
			str++;
		if (*str != c && *str)
		{
			tab[i++] = ft_dup(str, c);
			if (!tab)
				return (NULL);
		}
		while (*str != c && *str)
			str++;
	}
	tab[i] = NULL;
	return (tab);
}
