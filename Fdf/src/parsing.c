/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:14:43 by dvalenti          #+#    #+#             */
/*   Updated: 2018/04/27 17:39:10 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_move		*create_map(t_pars *str_map, t_move *data)
{
	t_pars		*ptr_sm;
	int			x;
	int			y;

	y = 0;
	if (!(data->map = (t_vect3**)malloc(sizeof(t_vect3*) * data->sizey)))
		return (NULL);
	if (!(data->map2 = (t_vect3**)malloc(sizeof(t_vect3*) * data->sizey)))
		return (NULL);
	ptr_sm = str_map;
	while (y < data->sizey)
	{
		data->map[y] = new_v0(ptr_sm->sizex);
		x = 0;
		while (x < data->sizex)
		{
			data->map[y][x].x = x;
			data->map[y][x].y = y;
			data->map[y][x].z = ft_getnbr(ptr_sm->str[x]);
			x++;
		}
		ptr_sm = ptr_sm->next;
		y++;
	}
	printf("%d %d\n", data->sizex, str_map->sizex);
	return (refresh(data));
}


t_move			*read_map(char **av, t_move *data)
{
	t_pars		*pars;
	t_pars		*ptr;
	int			y;
	int			fd;

	y = 0;
	if (!(pars = new_list()))
		return (NULL);
	ptr = pars;
	fd = open(av[1], O_RDONLY);
	while ((get_next_line(fd, &(ptr->line))) > 0 && (ptr->str = ft_strsplit(ptr->line, ' ')) && (ptr->next = new_list()))
	{
		while (ptr->str[ptr->sizex])
			ptr->sizex++;
		if (ptr->sizex != pars->sizex)
			return (NULL);
		y++;
		printf("%s | %d | %d\n", ptr->line, ptr->sizex, y); //PRINTF
		ptr = ptr->next;
	}
	data->sizex = pars->sizex;
	data->sizey = y;
	close(fd);
	return (create_map(pars, data));
}
