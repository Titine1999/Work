/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdouenia <bdouenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:21:15 by bdouenia          #+#    #+#             */
/*   Updated: 2017/12/06 16:06:46 by bdouenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

typedef struct			s_tetri
{
	char				c;
	int					x[4];
	int					y[4];
	struct s_tetri		*next;
}						t_tetri;

int						ft_algo(char **map, t_tetri *tetri, int size);
int						count_tetri(char *str);
void					creat_tetri(t_tetri **tmp, char *str);
t_tetri					*get_tetri(char *str);
char					*get_str(int fd);
int						check_line(char *gone, int j);
int						check_valide(char *gone, int j);
int						check_tetri(char *gone);
void					check_tetri_xy(t_tetri *tetri,
		t_tetri *locomotive, int count, char **map);
void					check_tetri_yx(t_tetri *tetri, char **map);
char					**creat_map(char **map, int size);
void					print_map(char **map, int size);
void					ft_solve(t_tetri *tetri);
char					**add_tetri(char **map, t_tetri *tetri, int size);
char					**rm_tetri(char **map, t_tetri *tetri, int size);
void					mv_tetri(t_tetri **tetri, int x, int y);
int						check_tetri_map(char **map, t_tetri *tetri, int size);

#endif
