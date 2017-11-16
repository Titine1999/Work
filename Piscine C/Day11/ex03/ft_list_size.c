/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 23:18:48 by dvalenti          #+#    #+#             */
/*   Updated: 2017/07/27 19:19:41 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int				ft_list_size(t_list *begin_list)
{
	t_list		*current;
	int			i;

	current = begin_list;
	i = 1;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}
