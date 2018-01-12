/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:54:09 by dvalenti          #+#    #+#             */
/*   Updated: 2018/01/12 11:36:36 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_mem    *new_list(int fd)
{
	t_mem	*res;

	if (!(res = (t_mem*)malloc(sizeof(t_mem))))
		return (NULL);
	res->rest = NULL;
	res->next = NULL;
	res->fd = fd;
	return (res);
}

int     gnl_core(int fd, char **line, char *lsi, t_mem *ptr)
{
	int     ret;
	char    buf[BUFF_SIZE + 1];

	if (ptr->rest)
		ptr->rest = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if ((ret == 0 && !*lsi) || ret < 0)
			return ((ret < 0) ? -1 : 0);
		buf[ret] = '\0';
		if ((!(ft_strchr(lsi, '\n')) && ret == 0 && (*line = lsi) == lsi))
			return (1);
		return (fill_rest(lsi, buf, ptr, line));
	}
	if (lsi && *lsi && (!(ft_strchr(lsi, '\n')) && ret == 0 && (*line = lsi) == lsi))
		return (1);
	return ((ret == 0) ? 0 : -1);
}

int   fill_rest(char *lsi, char *tmp, t_mem *ptr, char **line)
{
	if ((ft_strchr(tmp, '\n') != '\0') && (*line = ft_strjoin(lsi,   
					ft_strsub(tmp, 0, ft_strchr(tmp, '\n') - tmp))) 
			&& (ptr->rest = ft_strdup(ft_strchr(tmp, '\n') + 1)))
		return (1);
	return ((lsi && *lsi) ? gnl_core(ptr->fd, line, 
				ft_strjoin(lsi, tmp), ptr) : 
			gnl_core(ptr->fd, line, ft_strdup(tmp), ptr));
}

int     get_next_line(int fd, char **line)
{
	static t_mem    *mem = NULL;
	t_mem           *ptr;
	char            *lsi;

	if (fd < 0 || fd > 10024 || (!mem && !(mem = new_list(fd))) ||
			!(lsi = (char*)ft_memalloc(1)) || !line)
		return (-1);
	ptr = mem;
	while (ptr->next && ptr->fd != fd)
		ptr = ptr->next;
	if (ptr->fd != fd && !(ptr->next = new_list(fd)))
		return (-1);
	ptr = (ptr->fd == fd) ? ptr : ptr->next;
	if (ptr->rest)
		return (fill_rest(lsi, ptr->rest, ptr, line));
	return (gnl_core(fd, line, lsi, ptr));
}
