/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libqt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:26:51 by dvalenti          #+#    #+#             */
/*   Updated: 2018/04/26 17:10:50 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef 	LIBQT_H
# define	LIBQT_H

#include <math.h>
#include <stdlib.h>

typedef struct		s_quaternion
{
	float		x;
	float		y;
	float		z;
	float		t;
}					t_quaternion;

typedef float		t_vect3 __attribute__((ext_vector_type(3)));

float				calc_fpower(float a, float b);
float				lenght_quaternion(t_quaternion *q);
t_quaternion		*new_quaternion(float x, float y, float z,float t);
t_quaternion		*norm_quaternion(t_quaternion *q);
t_quaternion		*conj_quaternion(t_quaternion *q);
t_quaternion		*mult_quaternion(t_quaternion *q, t_quaternion *q2);
t_quaternion		*add_quaternion(t_quaternion *q, t_quaternion *q2);
t_quaternion		*subtract_quaternion(t_quaternion *q, t_quaternion *q2);
t_quaternion		*mult_scal_quaternion(t_quaternion *q, float k);
t_vect3				rotate_quaternion(t_quaternion *q, t_vect3 v0);
#endif
