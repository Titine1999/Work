/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:00:28 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/16 16:08:28 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		l;
	int		i;
	char	swp;

	i = 0;
	l = 0;
	while (str[l])
		l++;
	l--;
	while (l >= i)
	{
		swp = str[i];
		str[i] = str[l];
		str[l] = swp;
		l--;
		i++;
	}
	return (str);
}
