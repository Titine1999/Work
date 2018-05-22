/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:59:59 by dvalenti          #+#    #+#             */
/*   Updated: 2018/01/24 19:40:56 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_getnbr(char *str)
{
	int				res;
	char			*tmp;

	tmp = str;
	res = 0;
	if (!(str && *str))
		return (0);
	while (str && *str && (*str < '0' || *str > '9'))
		str++;
	while (str && *str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - 48);
		str++;
	}
	if (ft_strchr(tmp, '-'))
		res = res * (-1);
	return (res);
}
