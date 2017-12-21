/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 01:42:03 by dvalenti          #+#    #+#             */
/*   Updated: 2017/12/09 23:09:46 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	if (!size)
		return (NULL);
	if (!(mem = (unsigned char*)malloc(sizeof(*mem) * size)))
		return (NULL);
	ft_memset(mem, 0, size);
	return ((void*)mem);
}
