/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:52:28 by dvalenti          #+#    #+#             */
/*   Updated: 2018/03/20 15:59:46 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_nuclear		*new_nuclear(void)
{
	t_nuclear	*db;

	if (!(db = (t_nuclear*)malloc(sizeof(t_nuclear))))
		return (NULL);
	db->i = 0;
	db->flags = NULL;
	return (db);
}
