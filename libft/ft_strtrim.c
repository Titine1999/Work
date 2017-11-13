/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:04:56 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/12 11:46:41 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		len;

	len = ft_strlen(s);
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s)
	{
		while (*s != '\n' || *s != '\t' || *s != ' ')
			*new++ = *s++;
		s++;
	}
	return (new);
}
