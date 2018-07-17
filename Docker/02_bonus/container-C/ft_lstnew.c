/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:16:16 by dvalenti          #+#    #+#             */
/*   Updated: 2017/11/16 14:38:06 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void	const *content, size_t content_size)
{
	t_list		*new;
	void		*cpy;
	size_t		cpy_size;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		cpy = ft_memalloc(content_size);
		cpy_size = content_size;
		ft_memcpy(cpy, content, content_size);
		new->content = cpy;
		new->content_size = cpy_size;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}
