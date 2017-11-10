/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:07:18 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/10 23:30:51 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char const *d;
	
	d = s;
	while(d && *d != (unsigned char)c)
		d++;
	if (*d == '\0')
		return (NULL);
	return (d);
}
