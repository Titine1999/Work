/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:40:43 by dvalenti          #+#    #+#             */
/*   Updated: 2018/01/12 17:24:57 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	char 	*line;

	(void)ac;		
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error");
		return (1);
	}
	while ((get_next_line(fd, &line)))
		ft_putendl(line);
	return (0);
}
