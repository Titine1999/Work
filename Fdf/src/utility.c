/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:14:43 by dvalenti          #+#    #+#             */
/*   Updated: 2018/05/03 17:51:09 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

/*

   t_quaternion	b;

   b = (t_quaternion){.0, .0, .0, .0};
   */

void		rotate_vect(t_move *data, float rad, int i, int j, int k)
{
	t_quaternion	*p;
	t_quaternion	*q;
	int				x;
	int				y;

	y = 0;
	data->rot.x += 0;
	data->rot.y += 0;
	data->rot.z += 0;
	q = new_quaternion(cos(rad/2), i * sin (rad/2), j * sin(rad/2), k * sin(rad/2));
	q = norm_quaternion(q);
	while (y < data->sizey)
	{
		x = 0;
		while (x < data->sizex)
		{
			p = new_quaternion(0, data->map2[y][x].x, data->map2[y][x].y, data->map2[y][x].z);
			p = mult_quaternion(mult_quaternion(q,p), conj_quaternion(q));
			data->map2[y][x].x = p->y;
			data->map2[y][x].y = p->z;
			data->map2[y][x].z = p->t;
			x++;
		}
		y++;
	}
	data->rot.x = data->rot.x + cos(rad/2);
}

void		move_vect(t_move *data, float multx, float multy)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->sizey)

	{
		x = 0;
		while (x < data->sizex)
		{
			data->map2[y][x].x += multx;
			data->map2[y][x].y += multy;
			x++;
		}
		y++;
	}
	data->trans.x = data->trans.x + multx;
	data->trans.x = data->trans.y + multy;
}

void		scale_vect(t_move *data, float mult)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->sizey)
	{
		x = 0;
		while (x < data->sizex)
		{
			data->map2[y][x].x = (data->map2[y][x].x - 250 - data->sizex/2) *  mult + 250 + data->sizex/2;
			data->map2[y][x].y = (data->map2[y][x].y - 250 - data->sizey/2)  *  mult + 250 + data->sizey/2;
			data->map2[y][x].z *= mult;
			x++;
		}
		y++;
	}

}

void		print_map(t_move *data, float mult)
{
	int		i;
	int		j;

	(void)mult;
	j = 0;
	while (j < data->sizey)
	{
		i = 0;
		while(i < data->sizex)
		{
			if (data->map[j][i].z > 8)
				mlx_pixel_put(data->mlx, data->wn, data->map2[j][i].x /** multi*/ + 250, data->map2[j][i].y + 250 /** mult*/, 0x00FF0000);
			else
				if (data->map[j][i].z < 5)
					mlx_pixel_put(data->mlx, data->wn, data->map2[j][i].x /** mult*/ + 250, data->map2[j][i].y /** mult*/ + 250, 0x0000FF00);
				else
					mlx_pixel_put(data->mlx, data->wn, data->map2[j][i].x /** mult*/ + 250, data->map2[j][i].y /** mult*/ + 250, 0x00FFFFFF);
			i++;
		}
		j++;
	}
}

int		zoom(int key, t_move *data)
{
	if (key == 0)
		rotate_vect(data, M_PI/42, 0,  0, 1);
if (key == 12)
		rotate_vect(data, M_PI/42, 0, 1 , 1);
if (key == 14)
		rotate_vect(data, M_PI/42, 1, 1 , 0);
	if (key == 13)
		rotate_vect(data, M_PI/42, 1, 0 , 0);
if (key == 1)
		rotate_vect(data, -M_PI/42, 1, 0 , 0);
	if (key == 36)
		refresh(data);
	if (key == 49)
		scale_vect(data, 1.1);
	if (key == 126)
		move_vect(data, 0, -10);
	if (key == 6)
		scale_vect(data, 0.9);
	if (key == 125)
		move_vect(data, 0, 10);
	if (key == 124)
		move_vect(data, 10, 0);
	if (key == 123)
		move_vect(data, -10, 0);
	mlx_clear_window(data->mlx, data->wn);
	print_map(data, 1);
	printf("%d\n", key);
	return (1);
}
