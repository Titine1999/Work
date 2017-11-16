/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 16:58:17 by dvalenti          #+#    #+#             */
/*   Updated: 2017/07/18 16:05:53 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		main(int ac, char **av)
{
	int		x;
	int		y;

	while (ac > 1)
	{
		x = 0;
		y = ac - 1;
		while (av[y][x] != '\0')
		{
			ft_putchar(av[y][x]);
			x++;
		}
		ft_putchar('\n');
		ac--;
	}
	return (0);
}
