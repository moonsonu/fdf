/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:43:08 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/04 15:43:50 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		key_function(int key, t_env *m)
{
	init_struct(m);
	key == 53 ? exit(0) : 0;
	key == 7 ? m->x_angle -= M_PI / 60 : 0;
	key == 9 ? m->x_angle += M_PI / 60 : 0;
	key == 8 ? m->y_angle -= M_PI / 60 : 0;
	key == 2 ? m->y_angle += M_PI / 60 : 0;
	key == 6 ? m->z_angle += M_PI / 60 : 0;
	key == 0 ? m->z_angle -= M_PI / 60 : 0;
	key == 27 ? m->z_gap -= 5 : 0;
	key == 24 ? m->z_gap += 5 : 0;
	key == 125 ? m->y_move += 10 : 0;
	key == 126 ? m->y_move -= 10 : 0;
	key == 123 ? m->x_move -= 10 : 0;
	key == 124 ? m->x_move += 10 : 0;
	key == 15 ? read_dup(m) : 0;
	key == 31 ? m->gap -= 10 : 0;
	key == 34 ? m->gap += 10 : 0;
	key == 18 ? key_color_1_x(m) : 0;
	key == 19 ? key_color_2_x(m) : 0;
	key == 20 ? key_color_3(m) : 0;
	key == 21 ? key_color_4(m) : 0;
	ft_rotate(m);
	get_zxy(m);
}

void		key_zoom(int key, t_env *m)
{
	init_struct(m);
	if (key == 31)
		m->gap -= 10;
	if (key == 34)
		m->gap += 10;
	get_zxy(m);
	read_dup(m);
	}

int			keyfunction(int key, t_env *m)
{
	key == 53 ? key_function(key, m) : 0;
	(key >= 6 && key <= 9) || key == 0 || key == 2 ? key_function(key, m) : 0;
	(key == 24 || key == 27) ? key_function(key, m) : 0;
	(key >= 123 && key <= 126) ? key_function(key, m) : 0;
	key == 15 ? key_function(key, m) : 0;
	(key == 31 || key == 34) ? key_zoom(key, m) : 0;
	(key >= 18 && key <= 21) ? key_function(key, m) : 0;
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	mlx_message(m);
	get_zyx(m);
	ft_horizon(m);
	ft_vertic(m);
	mlx_key_hook(m->win_ptr, keyfunction, m);
	mlx_loop(m->mlx_ptr);
	return (0);
}
