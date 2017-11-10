/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:28:01 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/10 18:44:35 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcat(char *restrict s1, const char *restrict s2, size_t n)
{
	len = ft_strlen(s1);
	*s1 += len;
	while (*s2 && n > 0)
	{
		*s1++ = *s2++;
		len++;
		n--;
	}
	return (*s1 - len);
}
