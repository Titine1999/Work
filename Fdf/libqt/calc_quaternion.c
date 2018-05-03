/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_quaternion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 03:25:10 by dvalenti          #+#    #+#             */
/*   Updated: 2018/04/27 14:55:36 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libqt.h"

t_quaternion	*mult_quaternion(t_quaternion *q, t_quaternion *q2)
{
	t_quaternion	*r;
	
	r = new_quaternion(q->x * q2->x - q->y * q2->y - q->z * q2->z - q->t * q2->t, 
			q->x * q2->y + q->y * q2->x + q->z * q2->t - q->t * q2->z,
			q->x * q2->z - q->y * q2->t + q->z * q2->x + q->t * q2->y,
			q->x * q2->t + q->y * q2->z - q->z * q2->y + q->t * q2->x);

	return (r);
}

t_quaternion	*add_quaternion(t_quaternion *q, t_quaternion *q2)
{
	t_quaternion	*q3;

	if (!(q3 = new_quaternion(q->x + q2->x, q->y + q2->y, 
					q->z + q2->z, q->t - q2->t)))
		return(NULL);

	return (q3);
}

t_quaternion	*subtract_quaternion(t_quaternion *q, t_quaternion *q2)
 {
 	t_quaternion	*q3;

	if (!(q3 = new_quaternion(q->x - q2->x, q->y - q2->y, 
					q->z - q2->z, q->t - q2->t)))
		return (NULL);
	return (q3);
 }

t_quaternion	*mult_scal_quaternion(t_quaternion *q, float k)
{
	q->x *= k;
	q->y *= k;
	q->z *= k;
	q->t *= k;
	
	return (q);
}

t_vect3		rotate_quaternion(t_quaternion *q, t_vect3 v0)
{
	float	y;
	float	z;
	float	t;
	
	y = v0.x * (q->y * q->y + q->x * q->x - q->z * q->z - q->t * q->t) + v0.y * (2 * q->y * q->z - 2 * q->x * q->t) + v0.z * (2 * q->y * q->t + 2 * q->x * q->z);
	z = v0.x * (2 * q->x * q->t + 2 * q->y * q->z) + v0.y * (q->x * q->x - q->y * q->y + q->z * q->z - q->t * q->t) + v0.z * (-2 * q->x * q->y + 2 * q->z * q->t);
	t = v0.x * (-2 * q->x * q->z + 2 * q->y * q->z) + v0.y * (2 * q->x * q->y + 2 * q->z * q->t) + v0.z * (q->x * q->x - q->y * q->y + q->t * q->t);
	
	v0.x = y;
	v0.y = z;
	v0.z = t;

	return (v0);
}
