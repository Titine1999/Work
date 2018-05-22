/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <bdouenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 23:59:02 by bdouenia          #+#    #+#             */
/*   Updated: 2017/12/06 16:16:50 by bdouenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

char	**creat_map(char **map, int size)
{
	int y;
	int x;

	y = 0;
	if (!(map = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (y < size)
	{
		x = 0;
		if (!(map[y] = (char *)malloc(sizeof(char) * size + 1)))
			return (NULL);
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	return (map);
}

void	print_map(char **map, int size)
{
	int i;

	if (map == NULL)
		return (ft_putstr("error"));
	i = 0;
	while (i < size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

char	**add_tetri(char **map, t_tetri *tetri, int size)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetri->y[i] == y && tetri->x[i] == x)
			{
				map[y][x] = tetri->c;
				i++;
			}
			x++;
		}
		y++;
	}
	return (map);
}

char	**rm_tetri(char **map, t_tetri *tetri, int size)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map[y][x] == tetri->c)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}
