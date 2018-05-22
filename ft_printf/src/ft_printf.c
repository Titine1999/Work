/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:44:22 by dvalenti          #+#    #+#             */
/*   Updated: 2018/03/20 16:00:07 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

int		ft_printf(const char *str, ...)
{
	t_nuclear	*db;
	
	db = new_nuclear();
	db = ft_parsing(str, db);
	printf("%d\n", db[0].i);
	return (1);
}
