/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:54:09 by dvalenti          #+#    #+#             */
/*   Updated: 2018/01/12 06:45:51 by dvalenti         ###   ########.fr       */
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
	char	*tmp;  


	while (!ft_strchr(lsi, '\n') && (ret = read(fd, buf, BUFF_SIZE))) 
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		tmp = lsi;
		lsi = ft_strjoin(lsi, buf); 
		free(tmp);
	}
	return (fill_rest(lsi, ptr, line, ret));
}

int		fill_rest(char *tmp, t_mem *ptr, char **line, int ret)
{
	char	*newline;
	if (ret == 0 && !*tmp)
		return (0);
	if (!(newline = ft_strchr(tmp, '\n')) && (*line = tmp) == tmp)
		return ((ret == 0) ? 0 : 1);
	*newline = '\0';
	*line = ft_strdup(tmp);
	ptr->rest = ft_strdup(newline + 1);
	free(tmp);
	return (1);	
}	

int     get_next_line(int fd, char **line)
{
	static t_mem    *mem = NULL;
	t_mem           *ptr;
	char            *lsi;

	if (fd < 0 || fd > 10024 || (!mem && !(mem = new_list(fd))) ||
			!(lsi = (char*)ft_memalloc(1)))
		return (-1);
	if (*line)
		free(*line);
	ptr = mem;
	while (ptr && ptr->next && ptr->fd != fd)
		ptr = ptr->next;
	if (ptr->fd != fd && !(ptr->next = new_list(fd)))
		return (-1);
	if (ptr->rest)
	{
		free(lsi);
		lsi = ft_strdup(ptr->rest);
		free(ptr->rest);
	}
	return (gnl_core(fd, line, lsi, ptr));
}
