/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:10:02 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/16 15:45:25 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_strnword(char *str)
{
	int			i;

	i = 0;
	while (*str)
	{
		while (*str && (*str == '\t' || *str == ' ' || *str == '\n'))
			str++;
		if (*str && *str != '\t' && *str != ' ' && *str != '\n')
		{
			i++;
			while (*str && *str != '\t' && *str != ' ' && *str != '\n')
				str++;
		}
	}
	return (i);
}

static char		*ft_stridup(char *str)
{
	int			i;
	int			l;
	char		*dest;

	l = 0;
	while (str[l] && str[l] != ' ' && str[l] != '\t' && str[l] != '\n')
		l++;
	if (!(dest = (char*)malloc(sizeof(dest) * (l + 1))))
		return (NULL);
	i = -1;
	while (++i < l)
		dest[i] = str[i];
	dest[i] = 0;
	return (dest);
}

char			**ft_split_whitespaces(char *str)
{
	char		**tab;
	int			nb;
	int			boite;

	nb = ft_strnword(str);
	if (!(tab = (char**)malloc(sizeof(char*) * (nb + 1))))
		return (NULL);
	boite = -1;
	while (*str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		if (*str != ' ' && *str != '\t' && *str != '\0' && *str != '\n')
			tab[++boite] = ft_stridup(str);
		while (*str != ' ' && *str != '\t' && *str != '\0' && *str != '\n')
			str++;
	}
	tab[++boite] = 0;
	return (tab);
}
