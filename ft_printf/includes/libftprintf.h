/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:55:41 by dvalenti          #+#    #+#             */
/*   Updated: 2018/03/20 15:59:35 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...) __attribute__((format(printf,1,2)));

typedef struct			s_nuclear
{
		int				i;
		char*			flags;
}						t_nuclear;

t_nuclear				*ft_parsing(const char *str, t_nuclear *db);
t_nuclear				*new_nuclear(void);

#endif
