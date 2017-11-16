/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:22:56 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/16 10:48:39 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*fs;
	int		i;

	if (s && f)
	{
		i = 0;
		if (!(fs = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[i])
		{
			fs[i] = f(s[i]);
			i++;
		}
		fs[i] = '\0';
		return (fs);
	}
	return (NULL);
}
