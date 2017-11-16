/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 11:29:15 by dvalenti          #+#    #+#             */
/*   Updated: 2017/07/27 15:36:43 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		up;
	int		down;
	int		j;

	j = 0;
	i = -1;
	up = 0;
	down = 0;
	if (!(tab[i + 1]))
		return (1);
	while (++i < length)
	{
		if (tab[i] && tab[i + 1] && (f)(tab[i], tab[i + 1]) < 0)
			down = 1;
		else if (tab[i] && tab[i + 1] && (f)(tab[i], tab[i + 1]) > 0)
			up = 1;
		else if (tab[i] && tab[i + 1] && (f)(tab[i], tab[i + 1]) == 0)
			j++;
	}
	if ((down == 1 && up == 0) || (down == 0 && up == 1) || j == length)
		return (1);
	return (0);
}
