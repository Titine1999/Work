/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 03:04:10 by dvalenti          #+#    #+#             */
/*   Updated: 2018/05/03 17:43:19 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libqt/libqt.h"

/*
** STRUCTURES
*/
typedef struct		s_pars
{
	char			*line;
	char			**str;
	int				sizex;
	int				sizey;
	struct s_pars	*next;
}					t_pars;

typedef float			t_vect3 __attribute__((ext_vector_type(3)));

typedef struct		s_move
{
	t_vect3			**map;
	t_vect3			**map2;
	t_vect3			trans;
	t_vect3			rot;
	int				scale;
	int				scalez;
	int				sizex;
	int				sizey;
	void			*mlx;
	void			*wn;
}					t_move;

/*
** FONCTIONS D INITIALISATION
*/
t_move				*refresh(t_move *data);
t_vect3				*new_v0(int size);
t_pars				*new_list(void);
t_move				*create_map(t_pars *str_map, t_move *data);
t_move				*read_map(char **av, t_move *data);
void				print_map(t_move *data, float mult);
int					zoom(int key, t_move *data);
#endif
