/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 01:41:27 by tlux              #+#    #+#             */
/*   Updated: 2018/03/23 15:21:28 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void		pixel_put(t_xy *a, t_xy *b, t_utils utils)
{
	t_bresenham	s;
	int			xa;
	int			ya;
	int			xb;
	int			yb;

	xa = (int)a->x;
	ya = (int)a->y;
	xb = (int)b->x;
	yb = (int)b->y;
	s.i = ft_abs(xa - xb);
	s.j = ft_abs(ya - yb);
	s.k = xb < xa ? 1 : -1;
	s.l = yb < ya ? 1 : -1;
	s.m = (s.i > s.j ? s.i : -s.i) / 2;
	while (xb != xa || yb != ya)
	{
		mlx_pixel_put(MLX, WIN, xb, yb, 0x00FF00);
		s.n = s.m;
		s.n > -s.i ? s.m -= s.j : 1 == 1;
		s.n > -s.i ? xb += s.k : 1 == 1;
		s.n < s.j ? s.m += s.i : 1 == 1;
		s.n < s.j ? yb += s.l : 1 == 1;
	}
}

void		link_pixels(t_utils utils)
{
	t_xy *tmp;
	t_xy *cmp;

	tmp = ISO;
	while (tmp)
	{
		cmp = tmp;
		while (cmp)
		{
			if (cmp->rank == tmp->rank + 1 && (tmp->rank % (utils.grid_x + 1)))
				pixel_put(cmp, tmp, utils);
			if (cmp->rank == tmp->rank + utils.grid_x + 1)
				pixel_put(cmp, tmp, utils);
			cmp = cmp->next;
		}
		tmp = tmp->next;
	}
}

t_xy		*rot(t_utils utils)
{
	float	u;
	float	v;
	t_xy	*iso;
	t_point	*tmp;
	int		i;

	i = 1;
	iso = NULL;
	tmp = N_CO;
	utils.xmult = tmp->x * CZ * CY + tmp->y * SX * SY * CZ + tmp->y * CX *
		SZ + tmp->z * -1 * CX * SY * CZ + tmp->z * SX * SZ;
	utils.ymult = tmp->x * -1 * CY * SZ + tmp->y * -1 * SX * SY * SZ +
		tmp->y * CX * CZ + tmp->z * CX * SY * SZ + tmp->z * SX * CZ;
	utils.zmult = tmp->x * SY + tmp->y * -1 * CY * SX + tmp->z * CY * CX;
	while (tmp)
	{
		u = ((sqrt(2.0) / 2) * ((tmp->x * utils.xmult - tmp->y * utils.ymult)));
		v = ((sqrt(2.0 / 3.0)) * utils.zmult * tmp->z - ((1 / (sqrt(6.0))) *
					(tmp->x * utils.xmult + tmp->y * utils.ymult)));
		ft_xyadd(&iso, ft_xynew(SCALE * (u + tmp->x) + utils.tx + MAP_HEIGHT /
					2, SCALE * (v + tmp->y) + utils.ty + MAP_WIDTH / 2, i));
		tmp = tmp->next;
		i++;
	}
	return (iso);
}

int			deal_key(int key, void *param)
{
	t_utils *utils;

	utils = param;
	if (key == ESC)
	{
		ft_pointdel(&(utils->coords));
		ft_pointdel(&(utils->n_coords));
		ft_isodel(&(utils->iso));
		exit(0);
	}
	utils->rotx += (key == A ? PI / 48 : 0);
	utils->roty += (key == S ? PI / 48 : 0);
	utils->rotz += (key == D ? PI / 48 : 0);
	utils->tx -= (key == 123 ? 3 : 0);
	utils->tx += (key == 124 ? 3 : 0);
	utils->ty += (key == 125 ? 3 : 0);
	utils->ty -= (key == 126 ? 3 : 0);
	if (key == A || key == S || key == D || (key >= 123 && key <= 126))
	{
		mlx_clear_window(utils->mlx_ptr, utils->win_ptr);
		ft_isodel(&(utils->iso));
		utils->iso = rot(*utils);
		link_pixels(*utils);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_utils	utils;
	char	*line;
	char	**tmp;

	utils = init_struct();
	if (ac != 2 || !ft_strstr(av[1], ".fdf")
			|| (FD = open(av[1], O_RDONLY)) < 0)
		return (0);
	while (get_next_line(FD, &line) == 1)
	{
		if (!(tmp = ft_strsplit(line, " \t")))
			return (0);
		fill_list(tmp, &(CO), ++(utils.index));
		free(line);
		ft_tabfree(tmp);
	}
	free(line);
	N_CO = normalize_coords(CO, &utils);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, MAP_WIDTH, MAP_HEIGHT, "Projet FDF");
	mlx_hook(WIN, 2, 1L >> 2, deal_key, (void *)(&utils));
	ISO = rot(utils);
	link_pixels(utils);
	mlx_loop(MLX);
	return (0);
}
