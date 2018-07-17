/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:47:29 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/16 14:52:42 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del) (void*, size_t))
{
	t_list		*current;

	while (*alst)
	{
		current = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = current;
	}
	*alst = NULL;
}
