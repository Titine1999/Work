/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:30:57 by dvalenti          #+#    #+#             */
/*   Updated: 2018/01/24 19:39:41 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		**ft_createtab_strsplit(char const *s, char c)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return ((char **)malloc(sizeof(char *) * count + 1));
}

static char		*ft_returnstr_strsplit(char *tmp, char c)
{
	int			i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == c)
			tmp[i] = '\0';
		i++;
	}
	return (tmp);
}

static void		ft_putnull(int i[3])
{
	i[0] = 0;
	i[1] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char		**result;
	char		*tmp;
	int			i[3];

	if (s == NULL)
		return (NULL);
	tmp = ft_strdup(s);
	i[2] = ft_strlen(s);
	if (!(result = ft_createtab_strsplit(s, c)))
		return (NULL);
	tmp = ft_returnstr_strsplit(tmp, c);
	ft_putnull(i);
	while (i[0] < i[2])
	{
		if (!tmp[i[0]])
			i[0]++;
		else
		{
			result[i[1]] = ft_strdup(&tmp[i[0]]);
			i[1]++;
			i[0] += ft_strlen(&tmp[i[0]]);
		}
	}
	result[i[1]] = NULL;
	return (result);
}
