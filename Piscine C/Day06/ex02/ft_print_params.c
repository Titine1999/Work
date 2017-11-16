/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 18:54:14 by dvalenti          #+#    #+#             */
/*   Updated: 2017/07/19 00:19:33 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		main(int ac, char **av)
{
	int		x;
	int		y;

	y = 1;
	while (y < ac)
	{
		x = 0;
		while (av[y][x] != '\0')
		{
			ft_putchar(av[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	return (0);
}
