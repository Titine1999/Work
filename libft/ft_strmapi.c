/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 20:29:06 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/13 20:35:30 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int c, char))
{
	char	*fs;
	int		i;

	i = 0;
	if (!(fs = (char*)malloc(sizeof(char) * (ft_strlen(s)))))
		return (NULL);
	while (s && i != c)
	{
		*fs++ = f(i, *s++);
		i++;
	}
	return (fs);
}
