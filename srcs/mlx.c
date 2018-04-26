/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:19:07 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/24 21:15:18 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		init_struct(t_env *m)
{
	m->x_angle = 0;
	m->y_angle = 0;
	m->z_angle = 0;
	m->z_gap = 7;
}

void		mlx_message(t_env *m)
{

	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 5, 0xFFFFFF, "[ESC] : EXIT");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 550, 5, 0xFFFFFF, "X ROTATION : X, V");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 550, 25, 0xFFFFFF, "Y ROTATION : C, D");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 550, 45, 0xFFFFFF, "Z ROTATION : Z, A");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 550, 700, 0xFFFFFF, "Z -, +");
}

void		mlx(t_env *m)
{
	init_struct(m);
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, WIN_X, WIN_Y, "MOON");
	ft_horizon(m);
	ft_vertic(m);
	mlx_hook(m->win_ptr, 2, 0, key_board, m);
	mlx_message(m);
	mlx_loop(m->mlx_ptr);
}
