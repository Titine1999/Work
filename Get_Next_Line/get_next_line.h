/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:41:10 by dvalenti          #+#    #+#             */
/*   Updated: 2017/12/21 04:30:01 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#define BUFF_SIZE 32
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "libft/libft.h"

typedef struct		s_mem
{
	int		res;
	char	*rest;
	struct s_mem	*next;
}					t_mem;

int		get_next_line(const int fd, char **line);
#endif
