/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:29:58 by dvalenti          #+#    #+#             */
/*   Updated: 2018/01/12 17:49:54 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int del)
{
	char		*new;
	size_t		len;
	char		*tmp;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(new = ft_strnew(len)))
			return (NULL);
		tmp = new;
		tmp = ft_memcpy(tmp, s1, ft_strlen(s1));
		new = ft_strcat(tmp, s2);
		if (del == 1)
			free(s1);
		if (del == 2)
			free(s2);
		if (del == 3)
		{
			free(s1);
			s1 == NULL;
			free(s2);
			s
		}
		return (new);
	}
	return (NULL);
}
