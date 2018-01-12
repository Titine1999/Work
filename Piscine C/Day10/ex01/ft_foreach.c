/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 19:32:06 by dvalenti          #+#    #+#             */
/*   Updated: 2017/07/27 17:29:15 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_foreach(int *tab, int lenght, void (*f)(int))
{
	int		i;

	i = 0;
	while (tab[i] != '\0')
	{
		f(tab[i]);
		i++;
	}
}