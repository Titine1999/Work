/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 20:29:06 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/16 07:12:04 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*fs;
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		if(!(fs = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[i])
		{
			fs[i] = f(i, s[i]);
			i++;
		}
		return (fs);
	}
	return (NULL);
}
