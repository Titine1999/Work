/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 11:27:09 by dvalenti          #+#    #+#             */
/*   Updated: 2018/01/08 17:30:09 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*fill_buf(char *buf, char *lsi)
{
	char	*pls;
	char	*tmp;

	if(!(pls = ft_strdup(buf)))
		return (NULL);
	if ((tmp = ft_strchr(pls, '\n')))
		*tmp = '\0';
	if (!(lsi && *lsi))
	{
		if(!(lsi = ft_strdup(pls)))
			return (NULL);
	}
	else
	{
		if(!(lsi = ft_strjoin(lsi, pls)))
			return (NULL);
	}
	free(pls);
	return (lsi);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			*str;
	char 			buf[BUFF_SIZE + 1];
	t_mem			*mem;
	static t_mem	*locomotive = NULL;
	char			*lsi;

	mem = locomotive;
	if(!(lsi = ft_memalloc(BUFF_SIZE)))
		return (-1);
	if (fd < 0 || fd > 10024 || !line)
		return (-1);
	while (mem && mem->next && fd != mem->fd)
		mem = mem->next;
	if (mem  && fd == mem->fd)
	{
		if (mem->rest && (str = ft_strchr(mem->rest, '\n')))
		{
			if(!(lsi = fill_buf(mem->rest, lsi)))
				return (-1);
			if (!(*line = ft_strdup(lsi)))
				return (-1);
			free(lsi);
			*str = '\0';
			free(mem->rest);
			mem->rest = NULL;
			if (!(mem->rest = ft_strdup(++str)))
				return (-1);
			mem->patch = 1;
			return (1);
		}
		else if (mem->patch != 0)
		{
			if (mem->rest == NULL)
			{
				free(lsi);
				mem->patch = 0;
				return (0);
			}
			free(lsi);
			if(!(lsi = ft_strdup(mem->rest)))
				return(-1);
			free(mem->rest);
			mem->rest = NULL;
		}
	}
	else if (!locomotive)
	{
		if(!(locomotive = (t_mem*)ft_memalloc(sizeof(t_mem))))
			return (-1);
		mem = locomotive;
		mem->rest = ft_strnew(0);
		mem->fd = fd;
	}
	else
	{
		if (!(mem->next = (t_mem*)ft_memalloc(sizeof(t_mem))))
			return (-1);
		mem = mem->next;
		mem->rest = ft_strnew(0);
		mem->fd = fd;
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		str = lsi;
		if (!(lsi = fill_buf(buf, lsi)))
			return (-1);
		free(str);
		if ((str = ft_strchr(buf, '\n')))
		{
			if(!(mem->rest = ft_strdup(++str)))
				return (-1);
			if(!(*line = ft_strdup(lsi)))
				return (-1);
			free(lsi);
			mem->patch = 1;
			return (1);
		}
	}
	if (lsi && *lsi && ft_strlen(lsi) > 0)
	{
		if (!(*line = ft_strdup(lsi)))
			return (-1);
		free(lsi);
		mem->patch = 1;
		return (1);
	}
	mem->patch = 0;
	return (0);
}
