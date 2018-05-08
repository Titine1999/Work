/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 00:01:43 by tlux              #+#    #+#             */
/*   Updated: 2018/03/23 14:54:49 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_isodel(t_xy **todel)
{
	t_xy *cpy;
	t_xy *tmp;

	cpy = *todel;
	while (cpy)
	{
		tmp = cpy->next;
		free(cpy);
		cpy = tmp;
	}
	*todel = NULL;
}