/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <bdouenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:28:37 by bdouenia          #+#    #+#             */
/*   Updated: 2017/12/06 16:35:13 by bdouenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*transtet;
	t_tetri	*tetri;

	if (ac != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	transtet = (get_str(fd));
	if (!transtet || !check_tetri(transtet))
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	tetri = get_tetri(transtet);
	ft_solve(tetri);
	free(transtet);
	free(tetri);
	return (0);
}
