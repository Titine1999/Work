/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:04:56 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/16 09:21:01 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_strTlen(char const *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j] == '\n' || s[j] == '\t' || s[j] == ' ')
		++j;
	while (s[i] != '\0')
		i++;
	i--;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		--i;
	return (i - j + 1);
}

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		len;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	if(!s)
		return (NULL);
	len = ft_strTlen(s);
	if (len <= 0)
		len = 0;
	if (!(new = (char*)malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	while (s[j] == '\n' || s[j] == '\t' || s[j] == ' ')
	{
		++j;
	}
	while ( i < len)
		new[i++] = s[j++];
	new[i] = '\0';
	return (new);
}
