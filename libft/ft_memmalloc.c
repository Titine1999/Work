/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 10:34:42 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/13 21:40:50 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmalloc(size_t size)
{
	int		*mem;

	mem = 0;
	if (!(mem = (int*)malloc(sizeof(int) * (size))))
		return (NULL);
}
