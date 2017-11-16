/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 23:27:53 by dvalenti          #+#    #+#             */
/*   Updated: 2017/07/27 19:21:30 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list			*ft_list_last(t_list *begin_list)
{
	t_list		*current;

	current = begin_list;
	while (current != NULL)
		current = current->next;
	return (current);
}
