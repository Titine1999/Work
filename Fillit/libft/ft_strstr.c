/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 05:52:36 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/16 10:46:32 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		x;
	int		y;
	size_t	len;

	i = 0;
	y = 0;
	if (!(len = ft_strlen(needle)))
		return ((char*)haystack);
	while (haystack[i])
	{
		x = i;
		y = 0;
		while (haystack[x] == needle[y])
		{
			x++;
			y++;
			if (needle[y] == '\0')
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (0);
}
