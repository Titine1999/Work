/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:50:52 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/10 18:32:39 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	len = ft_strlen(s1);
	*s1 += len;
	while (*s2)
	{
		*s1++ = *s2++;
		len++;
	}
	return (*s1 - len);
}
