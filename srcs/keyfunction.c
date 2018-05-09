/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:43:08 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/08 23:05:03 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		key_function(int key, t_env *m)
{
	//init_struct(m);
	key == 53 ? exit(0) : 0;
	key == 7 ? m->x_angle -= M_PI / 60 : 0;
	key == 9 ? m->x_angle += M_PI / 60 : 0;
	key == 8 ? m->y_angle -= M_PI / 60 : 0;
	key == 2 ? m->y_angle += M_PI / 60 : 0;
	key == 6 ? m->z_angle += M_PI / 60 : 0;
	key == 0 ? m->z_angle -= M_PI / 60 : 0;
	key == 27 ? m->z_gap = -5 : 0;
	key == 24 ? m->z_gap = 5 : 0;
	key == 125 ? m->y_move = 10 : 0;
	key == 126 ? m->y_move = -10 : 0;
	key == 123 ? m->x_move = -10 : 0;
	key == 124 ? m->x_move = 10 : 0;
	//key == 15 ? init_struct(m) : 0;
	key == 18 ? key_color_1_x(m) : 0;
	key == 19 ? key_color_2_x(m) : 0;
	key == 20 ? key_color_3_x(m) : 0;
	//key == 21 ? key_color_4(m) : 0;
	ft_rotate(m, key);
	//prepare_pt(m);
	get_zxy(m);
//	printf("xangle[%f] yangle[%f] zangle[%f]\n", m->x_angle, m->y_angle, m->z_angle);
}

void		key_reset(/*int key, */t_env *m)
{
//	if (key == 15)
	init_struct(m);
	key_color_1_x(m);
	prepare_pt(m);
	get_zxy(m);
	//ft_rotate(m);
	//prepare_pt(m);
	//get_zxy(m);
}

void		key_zoom(int key, t_env *m)
{
	int i;
	int j;
	//init_struct(m);
	key == 31 ? m->zoom = 0.9 : 0;
	key == 34 ? m->zoom = 1.1 : 0;
	key == 31 ? m->zoom_x = (m->window / 20) : 0;
	key == 34 ? m->zoom_x = -(m->window / 20) : 0;
	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
		{
			m->pt_new[i][j].x = m->pt_new[i][j].x * m->zoom + (m->zoom_x);
			m->pt_new[i][j].y = m->pt_new[i][j].y * m->zoom + (m->zoom_x * 0.6);
		}
	}
	//prepare_pt(m);
	get_zxy(m);
}

int			keyfunction(int key, t_env *m)
{
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	key == 53 ? key_function(key, m) : 0;
	(key >= 6 && key <= 9) || key == 0 || key == 2 ? key_function(key, m) : 0;
	(key == 24 || key == 27) ? key_function(key, m) : 0;
	(key >= 123 && key <= 126) ? key_function(key, m) : 0;
	key == 15 ? key_reset(/*key, */m) : 0;
	(key == 31 || key == 34) ? key_zoom(key, m) : 0;
	(key >= 18 && key <= 21) ? key_function(key, m) : 0;
	mlx_message(m);
	ft_horizon(m);
	get_zyx(m);
	ft_vertic(m);
	mlx_hook(m->win_ptr, 2, 0, keyfunction, m);
	mlx_loop(m->mlx_ptr);
//	mlx(m);
	return (0);
}
