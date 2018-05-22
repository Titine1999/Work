/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:44:43 by dvalenti          #+#    #+#             */
/*   Updated: 2017/12/06 16:44:54 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

void	mv_tetri(t_tetri **tetri, int x, int y)
{
	int new_x;
	int new_y;
	int i;

	i = 0;
	new_x = 1000;
	new_y = 1000;
	while (i < 4)
	{
		if ((*tetri)->x[i] < new_x)
			new_x = (*tetri)->x[i];
		if ((*tetri)->y[i] < new_y)
			new_y = (*tetri)->y[i];
		i++;
	}
	i--;
	while (i >= 0)
	{
		(*tetri)->x[i] = (*tetri)->x[i] - new_x + x;
		(*tetri)->y[i] = (*tetri)->y[i] - new_y + y;
		i--;
	}
}

char	**algo(char **map, t_tetri *tetri, int size)
{
	int		x;
	int		y;
	char	**pam;

	if (tetri->next == NULL)
		return (map);
	pam = NULL;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			mv_tetri(&tetri, x, y);
			if (check_tetri_map(map, tetri, size))
				pam = algo(add_tetri(map, tetri, size), tetri->next, size);
			if (pam)
				return (pam);
			map = rm_tetri(map, tetri, size);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	ft_solve(t_tetri *tetri)
{
	char	**map;
	char	**result;
	int		size;

	size = 2;
	map = NULL;
	map = creat_map(map, size);
	result = NULL;
	while (!(result = algo(map, tetri, size)))
	{
		size++;
		ft_memdel((void **)map);
		map = creat_map(map, size);
	}
	print_map(result, size);
}
