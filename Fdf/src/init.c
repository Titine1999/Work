/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:10:41 by dvalenti          #+#    #+#             */
/*   Updated: 2018/04/27 17:32:15 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pars		*new_list(void)
{
	t_pars	*res;

	if (!(res = (t_pars*)malloc(sizeof(t_pars))))
		return (NULL);
	res->line = NULL;
	res->str = NULL;
	res->sizex = 0;
	res->sizey = 0;
	return (res);
}

t_vect3		*new_v0(int size)
{
	t_vect3	*vect;
	
	if (!(vect = (t_vect3*)malloc(sizeof(t_vect3) * size)))
		return (NULL);
	vect->x = 0;
	vect->y = 0;
	vect->z = 0;
	return (vect);
}

t_move		*refresh(t_move	*data)
{
	int		y;
	int		x;
	
	y = 0;
	while (y < data->sizey)
	{
		x = 0;
		data->map2[y] = new_v0(data->sizex);
		while (x < data->sizex)
		{
			data->map2[y][x].x = data->map[y][x].x;
			data->map2[y][x].y = data->map[y][x].y;
			data->map2[y][x].z = data->map[y][x].z;
			x++;
		}
		y++;
	}
	data->scale = 1;
	data->scalez = 1;
	data->trans.x = 0;
	data->trans.y = 0;
	return (data);
}
