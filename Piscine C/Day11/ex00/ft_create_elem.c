/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 22:00:18 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/16 11:43:24 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list			*ft_create_elem(void *data)
{
	t_list		*nouveau;

	if (!(nouveau = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	nouveau->data = data;
	nouveau->next = NULL;
	return (nouveau);
}
