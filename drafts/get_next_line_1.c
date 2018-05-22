/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:12:02 by dvalenti          #+#    #+#             */
/*   Updated: 2017/12/19 20:08:34 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_mem	*fill_rest(t_mem *mem, char *buf, int i)
{
	int		j;
	char	*tmp;

	i = 0;
	if (mem->rest == NULL)
	{
		mem->rest = ft_memalloc((mem->res) - i);
		j = 0;
	}
	else 
		j = ft_strlen(mem->rest);
	printf("...%s...\n%d\n", buf, j);
	while (buf[i] == '\n')
	{
		buf[i] = '\0';
		i++;
	}
	printf("i = %d, mem->res= %d\n", i, mem->res);
	while (i < (mem->res))
	{
		mem->rest[j] = buf[i];
		buf[i] = '\0';
		i++;
		j++;
		printf("mem = %d %d\n", i, j);
	}
	if (mem->rest)
	mem->res = mem->res + ft_strlen(mem->rest);
	printf("&&%s&&\n", mem->rest);
	return (mem);
}

char 	*fill_buf(char *buf, int i, int fd, t_mem *mem)
{
	char	*tmp;
	int		a;
	int		b;

	b = 0;
	a = 0;
	tmp = ft_strdup(buf);
	mem->res = 0;
	while(tmp[i] != '\n' && (mem->res = mem->res + read(fd, buf, BUFF_SIZE)))
	{
		tmp = ft_strjoin(tmp, buf);
		printf("@@%s@@\n", tmp);
		while (tmp[i] != '\0' && tmp[i] != '\n')
			i++;
	}
	printf("----%s---\n", buf);
	while (buf[a] == '\n')
		a++;
	while (buf[a] != '\n' && buf[a] != '\0')
		a++;
	a++;
	while (buf[a] != '\0')
		{
			mem->rest[b] = buf[a];
			a++;
			b++;
		}
	free(buf);
	return (tmp);
}


int		get_next_line(int fd, char **line)
{
	static t_mem	*mem;
	char			*buf;
	int				i;

	i = 0;
	buf = ft_strnew(BUFF_SIZE);
	if (!mem)
	{
		mem = ft_memalloc(sizeof(t_mem));
		*line = NULL;
	}
	else 
	{
		*line = ft_strdup(mem->rest);
		mem->rest = ft_strchr(mem->rest, '\n');
		if (mem->rest)
		{
			(mem->rest)++;
			while (line[0][i] != '\n')
				i++;
			while (line[0][i] != '\0')
			{
				line[0][i] = '\0';
				i++;
			}
			printf("==%s==\n[%s]\n", *line, mem->rest);
			return (1);
		}
		printf("||%s||\n", mem->rest);
	}
	if (fd < 0 || fd > 10024)
		return (-1);
	//	printf("*line = %s | buf = %s | rest = %s\n", *line, buf, mem->rest);
	if (!((mem->res) = read(fd, buf, BUFF_SIZE)))
		return (0);
	//	printf("*line = %s | buf = %s | rest = %s\n", *line, buf, mem->rest);
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	//	printf("*line = %s | buf = %s | rest = %s\n", *line, buf, mem->rest);
	if (buf[i] != '\0')
		mem = fill_rest(mem, buf, i);
	else if(buf[i] == '\0')
	{
		buf = fill_buf(buf, i, fd, mem);
		printf("::%s::\n", mem->rest);
		while(buf[i] != '\n')
			i++;
		if (buf[i] != '\0')
			mem = fill_rest(mem, buf, i);
	}
	//	printf("*line = %s | buf = %s | rest = %s\n", *line, buf, mem->rest);
	if (*line != '\0')
		*line = ft_strjoin(*line, buf);
	else
		*line = ft_strdup(buf);
	free(buf);
	printf("==%s==\n[%s]\n", *line, mem->rest);
	return(0);
}
