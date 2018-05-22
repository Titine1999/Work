/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:58:43 by dvalenti          #+#    #+#             */
/*   Updated: 2018/03/20 15:46:54 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_nuclear*		count_parameter(char *str, t_nuclear* db)
{
	int		i;
	char	*ptr;

	ptr = str;
	i = 0;
	while (ptr && *ptr && (ptr = ft_strchr(ptr, '%')))
	{
		if (*(ptr + 1) == '%')
			ptr++;
		else
			i++;
		ptr++;
	}
	db[0].i = i;
	i = 1;
	while (i < db[0].i)
	{
		db[i].i = db[0].i;
		i++;
	}
	return (db);
}

t_nuclear*		ft_parsing(const char *str, t_nuclear* db)
{
	char	*ptr;

	ptr = (char*)str;
	db = count_parameter(ptr, db);

	return (db);	
}
