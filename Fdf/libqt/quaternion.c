/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:49:22 by dvalenti          #+#    #+#             */
/*   Updated: 2018/04/27 14:56:22 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libqt.h"

t_quaternion	*new_quaternion(float x, float y, float z, float t)
{
	t_quaternion	*q;

	if(!(q = (t_quaternion*)malloc(sizeof(t_quaternion))))
		return (NULL);
	q->x = x;
	q->y = y;
	q->z = z;
	q->t = t;
	
	return (q);
}

float		lenght_quaternion(t_quaternion *q)
{
	return (sqrt(q->x * q->x + q->y * q->y + q->z * q->z + q->t * q->t));
}

t_quaternion	*norm_quaternion(t_quaternion *q)
{
	float	l;

	l = lenght_quaternion(q);
	q->x /= l;
	q->y /= l;
	q->z /= l;
	q->t /= l;
	
	return (q);
}

t_quaternion	*conj_quaternion(t_quaternion *q)
{
	t_quaternion 	*s;

	s = new_quaternion(q->x, -q->y, -q->z, -q->t);

	return (s);
}

