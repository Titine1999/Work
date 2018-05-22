/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 08:22:55 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/16 08:53:36 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long res;

	res = (long)n;
	if (res < 0)
	{
		ft_putchar_fd('-', fd);
		res = -res;
	}
	if (res >= 10)
	{
		ft_putnbr_fd((res / 10), fd);
	}
	ft_putchar_fd((res % 10 + '0'), fd);
}
