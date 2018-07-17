/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 10:51:57 by dvalenti          #+#    #+#             */
/*   Updated: 2017/12/21 03:38:50 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
		return (new);
	}
	return (NULL);
}
