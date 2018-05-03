/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-pass <gde-pass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 22:18:35 by gde-pass          #+#    #+#             */
/*   Updated: 2018/03/23 15:23:25 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ESC 53
# define A 0
# define S 1
# define D 2
# define PI 3.14159265358979323846
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# define MAP_WIDTH 1080
# define MAP_HEIGHT 960
# define IMG_WIDTH 720
# define IMG_HEIGHT 576
# define WIN utils.win_ptr
# define MLX utils.mlx_ptr
# define FD utils.fd
# define CO utils.coords
# define N_CO utils.n_coords
# define ISO utils.iso
# define SCALE 5
# define CZ cos(utils.rotz)
# define SZ sin(utils.rotz)
# define CY cos(utils.roty)
# define SY sin(utils.roty)
# define CX cos(utils.rotx)
# define SX sin(utils.rotx)
# define XP tmp->x * utils.xmult
# define YP tmp->y * utils.ymult
# define ZP tmp->z * utils.zmult

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	struct s_point	*next;
	int				size;
}					t_point;
typedef struct		s_xy
{
	float			x;
	float			y;
	int				rank;
	struct s_xy		*next;
}					t_xy;
typedef struct		s_utils
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				fd;
	int				grid_x;
	int				grid_y;
	float			rotx;
	float			roty;
	float			rotz;
	float			tx;
	float			ty;
	float			xmult;
	float			ymult;
	float			zmult;
	int				index;
	t_point			*coords;
	t_point			*n_coords;
	t_xy			*iso;
}					t_utils;
typedef struct		s_bresenham
{
	int				i;
	int				j;
	int				m;
	int				n;
	int				k;
	int				l;
}					t_bresenham;
t_point				*normalize_coords(t_point *coords, t_utils *utils);
t_utils				init_struct(void);
t_utils				init_struct(void);
void				find_size(t_point *coords, int *width, int *height, int *z);
void				fill_list(char **tmp, t_point **coords, int index);
int					ft_abs(int i);
void				link_pixels(t_utils utils);
int					deal_key(int key, void *param);
t_xy				*rot(t_utils utils);
void				pixel_put(t_xy *a, t_xy *b, t_utils utils);

#endif
