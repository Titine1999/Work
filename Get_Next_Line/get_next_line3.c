/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:54:09 by dvalenti          #+#    #+#             */
/*   Updated: 2018/01/12 07:22:13 by dvalenti         ###   ########.fr       */
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
//	printf("\033[32mnew_list : OK\n\033[0mres->fd = %d\n", res->fd);
	return (res);
}

int     gnl_core(int fd, char **line, char *lsi, t_mem *ptr)
{
	int     ret;
	char    buf[BUFF_SIZE + 1];
	char	*str1;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		printf("\033[33mbuff = [\033[0m%s\033[33m]\033[0m\nlsi = %s\n", buf, lsi);
	if ((!(str1 = ft_strchr(buf, '\n')) && (*line = ft_strjoin(lsi,buf))         // Cas de fin de fichier && Erreurs
				&& ret <= 0) || (ret <= 0 && !*buf))
			return ((ret == 0) ? 0 : -1);
		return (fill_rest(lsi, buf, ptr, line));
	}
	return (-1);
}

int   fill_rest(char *lsi, char *tmp, t_mem *ptr, char **line)
{
	char    *str;

//	if (!(str = ft_strch(tmp, '\n')) && (*line = ft_strjoin(lsi,tmp)))
//			return ((ret == 0) ? 0 : gnl_core(ptr->fd, line, lsi ,ptr));
	if ((str = ft_strchr(tmp, '\n')))
	{
		*str = '\0';
		*line = ft_strdup(tmp);
		ptr->rest = ft_strdup(++str);
		printf("\033[1mline = %s\n\033[35mrest= %s\033[0m\n", *line, ptr->rest);
		return (1);
	}
//	printf("\033[35mrest= %s\033[0m\n", tmp);
//	if (!(lsi && *lsi))
//	{
//		printf("~STRDUP~\n");
//		lsi = ft_strdup(tmp);
//	}
//	else
	{
//		printf("~STRJOIN~\n");
//		lsi = ft_strjoin(lsi, tmp);
	}
	printf("\033[35mrest= %s\033[0m\nlsi = %s\n", tmp, lsi);
	free(tmp);
	return (gnl_core(ptr->fd, line, lsi, ptr));
}

int     get_next_line(int fd, char **line)
{
	static t_mem    *mem = NULL;
	t_mem           *ptr;
	char            *lsi;

	if (fd < 0 || fd > 10024 || (!mem && !(mem = new_list(fd))) ||
			!(lsi = (char*)ft_memalloc(1)))
		return (-1);
//	printf("\033[1m------DEBUT------\n\033[0m");
	if (*line)
		free(*line);
//	printf("\033[34m----DEBUT : (MEM) = ? ----\n\033[0m");
	ptr = mem;
//	printf("fd = %d, ptr->fd = %d\n", fd, ptr->fd);
	printf("\033[34m----DEBUT : (MEM) = 1 ----\n\033[0m");
	while (ptr && ptr->next && ptr->fd != fd)
		ptr = ptr->next;
//	printf("fd = %d, ptr->fd = %d\n", fd, ptr->fd);
	if (ptr->fd != fd && !(ptr->next = new_list(fd)))
		return (-1);
	else if (ptr->rest)
		return (fill_rest(lsi, ptr->rest, ptr, line));
	return (gnl_core(fd, line, lsi, ptr));
}
