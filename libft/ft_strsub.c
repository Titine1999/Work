/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 10:41:25 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/12 11:03:27 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new;

	if(!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL):
	while (s && *s != s[start])
	s++;
	while (start != len + 1)
		*new = s[start++];
	return (new);
}
