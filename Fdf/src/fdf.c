/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:14:43 by dvalenti          #+#    #+#             */
/*   Updated: 2018/05/03 17:52:02 by dvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	t_move	*data;
	(void)ac;
	
	if(!(data = (t_move*)malloc(sizeof(t_move))))
		return (-1);
	data->mlx = mlx_init();
	data->wn = mlx_new_window(data->mlx, 500, 500, "~FDF~");
	if(!(data = read_map(av, data)))
		return (-1);
	print_map(data, 1);
	mlx_hook(data->wn, 2, 0, zoom, data);
	mlx_loop(data->mlx);
	return (0);
}
//2 appuie
//3 relache

//4 appuie (souris)
//5 relache
//6 bouge

//17 ferme la fenetre
