/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <bdouenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:50:40 by bdouenia          #+#    #+#             */
/*   Updated: 2017/12/06 16:16:26 by bdouenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int				count_tetri(char *str)
{
	int			result;

	result = 0;
	while (*str)
	{
		if (*str == '#')
			result++;
		str++;
	}
	return (result / 4);
}

void			creat_tetri(t_tetri **tmp, char *str)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			(*tmp)->x[j] = i % 5;
			(*tmp)->y[j] = i / 5;
			j++;
		}
		i++;
	}
}

t_tetri			*get_tetri(char *str)
{
	int			nb_tetri;
	t_tetri		*locomotive;
	t_tetri		*tmp;
	int			add21;
	char		c;

	add21 = 0;
	c = 'A';
	nb_tetri = count_tetri(str);
	if (!(locomotive = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	tmp = locomotive;
	while (nb_tetri > 0)
	{
		tmp->c = c;
		creat_tetri(&tmp, ft_strsub(str, 0 + add21, 20));
		if (!(tmp->next = (t_tetri *)malloc(sizeof(t_tetri))))
			return (NULL);
		tmp = tmp->next;
		nb_tetri--;
		add21 += 21;
		c++;
	}
	tmp->next = NULL;
	return (locomotive);
}

char			*get_str(int fd)
{
	int			f;
	int			i;
	char		c;
	char		*str;

	i = 0;
	str = NULL;
	f = read(fd, &c, 1);
	if (f < 0)
		return (NULL);
	if (f == 1)
	{
		str = (char *)malloc(sizeof(char) * 600);
		while (f != '\0')
		{
			str[i] = c;
			i++;
			f = read(fd, &c, 1);
		}
		str[i] = '\0';
	}
	return (str);
}
