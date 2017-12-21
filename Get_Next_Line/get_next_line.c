/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 11:27:09 by dvalenti          #+#    #+#             */
/*   Updated: 2017/12/21 06:15:28 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*fill_buf(char *buf, char *lsi)
{
	char	*pls;
	char	*tmp;

	pls = ft_strdup(buf);
	if ((tmp = ft_strchr(pls, '\n')))
		*tmp = '\0';
	if (!(lsi && *lsi))
		lsi = ft_strdup(pls);
	else
		lsi = ft_strjoin(lsi, pls);
	free(pls);
	return (lsi);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			*str;
	char 			buf[BUFF_SIZE + 1];
	static t_mem	*mem = NULL;
	char			*lsi;

	lsi = ft_memalloc(BUFF_SIZE);
	if (fd < 0 || fd > 10024)
		return (-1);
	if (mem)
	{
		if (mem->rest && (str = ft_strchr(mem->rest, '\n')))
		{
			lsi = fill_buf(mem->rest, lsi);
			*line = ft_strdup(lsi);
			free(lsi);
			*str = '\0';
			free(mem->rest);
			mem->rest = ft_strdup(str + 1);
			return (1);
		}
		else
		{
			if (mem->rest == NULL)
			{
				free(lsi);
				return (0);
			}
				free(lsi);
			lsi = ft_strdup(mem->rest);
			free(mem->rest);
			mem->rest = NULL;
		}
	}
	else	
		mem = (t_mem*)ft_memalloc(sizeof(t_mem));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		str = lsi;
		lsi = fill_buf(buf, lsi);
		free(str);
		if ((str = ft_strchr(buf, '\n')))
		{
			mem->rest = ft_strdup(++str);
			*line = ft_strdup(lsi);
			free(lsi);
			return (1);
		}
	}
	if (lsi && *lsi && ft_strlen(lsi) > 0)
	{
		*line = ft_strdup(lsi);
		free(lsi);
		return (1);
	}
	return (0);
}
