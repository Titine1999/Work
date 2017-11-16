/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 00:06:00 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/16 12:43:18 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			ft_list_clear(t_list **begin_list)
{
	t_list		*current;
	t_list		*bus;

	current = *begin_list;
	while (current->next)
	{
		bus = current;
		bus->next = current->next;
		free(current);
		current = bus->next;
	}
	free(bus);
	current->next = NULL;
}
