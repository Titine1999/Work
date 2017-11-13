/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:22:56 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/13 21:37:53 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*fs;

	if (!(fs = (char*)malloc(sizeof(char) * (ft_strlen(s)))))
		return (NULL);
	while (s)
		*fs++ = f(*s++);
	return (fs);
}
