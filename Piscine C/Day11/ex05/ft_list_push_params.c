/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 23:33:43 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/16 11:49:11 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_psuh_params(int ac, char **av)
{
	int		i;
	t_list	*wagon;
	t_list	*current;
	t_list	*locomotive;

	i = ac;
	while (i > 0)
	{
		wagon = ft_create_elem(av[i]);
		current = current->next;
		i--;
	}
	locomotive = ft_create_elem(av[ac]);
	return (locomotive);
}
