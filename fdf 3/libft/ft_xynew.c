/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:30:41 by tlux              #+#    #+#             */
/*   Updated: 2018/03/21 22:12:13 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_xy	*ft_xynew(float x, float y, int rank)
{
	t_xy *node;

	if (!(node = (t_xy *)malloc(sizeof(*node))))
		return (0);
	node->x = x;
	node->y = y;
	node->rank = rank;
	node->next = NULL;
	return (node);
}
