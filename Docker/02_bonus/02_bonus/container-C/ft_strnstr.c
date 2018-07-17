/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 01:56:14 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/16 10:49:32 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	size_t			n;

	i = 0;
	if (!(n = ft_strlen(needle)))
		return ((char*)haystack);
	while (*haystack && i < len)
	{
		if (!(ft_strncmp(haystack, needle, n)))
		{
			if (n + i > len)
				return (NULL);
			return ((char*)haystack);
		}
		haystack++;
		i++;
	}
	return (0);
}
