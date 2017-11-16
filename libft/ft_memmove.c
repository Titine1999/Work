/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:41:28 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/15 22:13:37 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char buf[len];
	
	if (len >= 128 * 1024 * 1024)
		return (NULL);
	ft_memcpy(buf, src, len);
	ft_memcpy(dst, buf, len);	
	return (dst);
}
