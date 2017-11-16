/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:06:27 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/16 10:56:15 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strcnword(const char *str, char c)
{
	int			i;

	i = 0;
	while (*str)
	{
		while (*str && (*str == c))
			str++;
		if (*str && *str != c)
		{
			i++;
			while (*str && *str != c)
				str++;
		}
	}
	return (i);
}

static char		*ft_strcdup(const char *str, char c)
{
	int			i;
	int			l;
	char		*dest;

	l = 0;
	while (str[l] && str[l] != c)
		l++;
	if (!(dest = (char*)malloc(sizeof(dest) * (l + 1))))
		return (NULL);
	i = -1;
	while (++i < l)
		dest[i] = str[i];
	dest[i] = 0;
	return (dest);
}

char			**ft_strsplit(const char *s, char c)
{
	char		**tab;
	int			nb;
	int			boite;

	if (!s || !c)
		return (NULL);
	nb = ft_strcnword(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (nb + 1))))
		return (NULL);
	boite = 0;
	while (boite < nb)
	{
		while (*s == c)
			s++;
		if (*s != c)
			tab[boite++] = ft_strcdup(s, c);
		while (*s != c)
			s++;
	}
	tab[nb] = 0;
	return (tab);
}
