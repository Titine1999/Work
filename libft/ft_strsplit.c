/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:48:34 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/13 21:39:03 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char const *s)
{
	int		l;

	while (s)
	{
		while (*s != ' ' && *s != '\t' && *s != '\n')
			*s++;
		l++;
		while (*s == ' ' || *s == '\t' || *s == '\n')
			*s++;
	}
	return (l);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		len;

	len = ft_countwords(s);
	if (!(new = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	while (s)
	{
		while (*s != ' ' && *s != '\t' && *s != '\n')
			**new++ = *s++;
		if (*s == ' ' || *s == '\t' || *s == '\n')
			*new++;
	}
	return (new);
}
