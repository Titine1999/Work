/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:40:43 by dvalenti          #+#    #+#             */
/*   Updated: 2017/12/21 05:25:21 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char 	*line;
	
	if (ac > 1)
	{
	//	while (i < ac)	
	//	{
			fd = open(av[1], O_RDONLY);
			if (fd == -1)
			{
				ft_putstr("error");
				return (1);
			}
//			printf("------------\n");
			while ((get_next_line(fd, &line)))
				ft_putendl(line);
		//	get_next_line(fd, line);
	//	  }
	//	i++;
		}	
	return (0);
}
