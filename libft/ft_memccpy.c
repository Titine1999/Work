/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:28:16 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/13 21:47:30 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*d;
	char const		*s;

	d = dst;
	s = src;
	while (n && (unsigned char)c != *s)
	{
		*d++ = *s++;
		n--;
	}
	return (dst);
}
