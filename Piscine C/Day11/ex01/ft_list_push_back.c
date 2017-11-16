/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 22:16:32 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/16 11:59:51 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			ft_list_push_back(t_list **begin_list, void *data)
{
	t_list		*news;
	t_list		*current;

	current = *begin_list;
	news = ft_create_elem(data);
	while (current != NULL)
		current = current->next;
	current = news;
}
