/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 18:00:41 by dvalenti          #+#    #+#             */
/*   Updated: 2017/07/19 19:27:55 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int		ft_print_params(int ac, char **av)
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

int		main(int ac, char **av)
{
	int		i;
	char	*mid;
	int		y;

	i = 1;
	y = 1;
	while (y < ac - 1)
	{
		if (ft_strcmp(av[y], av[y + 1]) > 0)
		{
			mid = av[y];
			av[y] = av[y + 1];
			av[y + 1] = mid;
			y = 0;
		}
		y++;
	}
	ft_print_params(ac, av);
}
