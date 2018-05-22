/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:12:02 by dvalenti          #+#    #+#             */
/*   Updated: 2017/12/16 12:38:23 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_mem	*fill_rest(t_mem *mem, char *buf, int i, char *rest)
{
	int		j;
	
	j = 0;
	mem->rest = ft_memalloc((mem->res) - i);
	while (buf[i] == '\n')
	{
		buf[i] = '\0';
		i++;
	}
	while (i < (mem->res))
	{
		mem->rest[j] = buf[i];
		buf[i] = '\0';
		i++;
		j++;
	}
	mem->res = ft_strlen(mem->rest);
	return (mem);
}

char 	*fill_buf(char *buf, int i, int fd, t_mem *mem)
{
	char	*tmp;

	tmp = ft_strdup(buf);
	mem->res = 0;
	while((mem->res = mem->res + read(fd, buf, BUFF_SIZE)) && tmp[i] != '\n')
	{
		tmp = ft_strjoin(tmp, buf);
		while (tmp[i] != '\0' && tmp[i] != '\n')
			i++;
	}
	free(buf);
	return (tmp);
}


int		get_next_line(int fd, char **line)
{
	static t_mem	*mem;
	char			*buf;
	int				i;
	char			*rest;

	i = 0;
	if (!mem)
	{
		mem = ft_memalloc(sizeof(t_mem));
		*line = NULL;
	}
	else 
	{
			*line = ft_strdup(mem->rest);
			rest = ft_strchr(mem->rest, '\n');
			printf("||%s||\n", rest);
	}
	buf = ft_memalloc(BUFF_SIZE + 1);
	if (fd < 0 || fd > 10024)
		return (-1);
	if (!((mem->res) = read(fd, buf, BUFF_SIZE)))
		return (0);
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] != '\0')
		mem = fill_rest(mem, buf, i, rest);
	else if(buf[i] == '\0')
	{
		buf = fill_buf(buf, i, fd, mem);
		while(buf[i] != '\n')
			i++;
		if (buf[i] != '\0')
			mem = fill_rest(mem, buf, i, rest);
	}
	if (*line != '\0')
		*line = ft_strjoin(*line, buf);
	else
		*line = ft_strdup(buf);
	free(buf);
	printf("==%s==\n[%s]\n", *line, mem->rest);
	return(0);
}
