/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 08:49:17 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/16 08:53:56 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long int n;

	n = nb;
	if (n < 0)
	{
		n = n * -1;
		ft_putchar('-');
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + 48);
}
