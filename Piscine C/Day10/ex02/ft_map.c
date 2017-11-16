/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 10:36:48 by dvalenti          #+#    #+#             */
/*   Updated: 2017/07/27 17:47:43 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int lenght, int (*f)(int))
{
	int		i;
	int		*tabdest;

	i = 0;
	if (!(tabdest = (int*)malloc(sizeof(int) * (lenght))))
		return (NULL);
	while (i < lenght)
	{
		tabdest[i] = f(tab[i]);
		i++;
	}
	return (tabdest);
}
