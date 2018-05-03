/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:16:27 by tlux              #+#    #+#             */
/*   Updated: 2018/03/23 15:21:18 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int			ft_abs(int i)
{
	return ((i < 0 ? -i : i));
}

void		fill_list(char **tmp, t_point **coords, int index)
{
	int i;

	i = 0;
	while (tmp[i] != NULL)
	{
		if (ft_isstrdigit(tmp[i]))
			ft_pointadd(coords, ft_pointnew(index, i, ft_atoi(tmp[i])));
		else
		{
			ft_pointdel(coords);
			ft_tabfree(tmp);
			exit(0);
		}
		i++;
	}
}

void		find_size(t_point *coords, int *width, int *height, int *z)
{
	t_point *tmp;

	tmp = coords;
	*width = -2147483648;
	*height = -2147483648;
	*z = -2147483648;
	while (tmp->next->x == 0)
		tmp = tmp->next;
	*width = tmp->y;
	while (tmp)
	{
		if (((tmp->next && !tmp->next->y) || !(tmp->next)) && tmp->y != *width)
		{
			ft_pointdel(&coords);
			exit(0);
		}
		if (tmp->x > *height)
			*height = tmp->x;
		if (tmp->z > *z)
			*z = tmp->z;
		tmp = tmp->next;
	}
	if (*z == 0)
		*z = 1;
}

t_utils		init_struct(void)
{
	t_utils utils;

	utils.coords = NULL;
	utils.rotx = 5.6;
	utils.roty = 0;
	utils.rotz = 0;
	utils.tx = 0;
	utils.ty = 0;
	utils.xmult = 0;
	utils.ymult = 0;
	utils.zmult = 0;
	utils.index = -1;
	return (utils);
}

t_point		*normalize_coords(t_point *coords, t_utils *utils)
{
	t_point	*tmp;
	t_point	*norm;
	int		width;
	int		height;
	int		zmax;

	norm = NULL;
	find_size(coords, &width, &height, &zmax);
	utils->grid_x = width;
	utils->grid_y = height;
	tmp = coords;
	while (tmp)
	{
		ft_pointadd(&norm, ft_pointnew(tmp->x - height /
					2, tmp->y - width / 2, tmp->z / zmax * 1.5));
		tmp = tmp->next;
	}
	return (norm);
}
