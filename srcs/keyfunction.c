/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:43:08 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/26 18:02:03 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		key_escape(int key)
{
	if (key == 53)
	{
		exit(0);
		return (0);
	}
	return (0);
}

void		key_rot(int key, t_env *m)
{
	//x7 v9 c8 d2 z6 a0
	key == 7 ? m->x_angle -= M_PI / 30 : 0;
	key == 9 ? m->x_angle += M_PI / 30 : 0;
	key == 8 ? m->y_angle -= M_PI / 30 : 0;
	key == 2 ? m->y_angle += M_PI / 30 : 0;
	key == 6 ? m->z_angle -= M_PI / 30 : 0;
	key == 0 ? m->z_angle += M_PI / 30 : 0;
}

void		key_z(int key, t_env *m)
{
	//27minus 24equal
	if (key == 27)
	{
		m->z_gap = 0;
		m->z_gap -= 5;
		get_zxy(m);
	}
	else if (key == 24)
	{
		m->z_gap = 0;
		m->z_gap += 5;
		get_zxy(m);
	}
}

//void		key_move(int key, t_env *m)
//{
	//down125 up126 left123 right 124
//	key == 125 ?
//}

int			keyfunction(int key, t_env *m)
{
	key == 53 ? key_escape(key) : 0;
	(key >= 6 && key <= 9) || key == 0 || key == 2 ? key_rot(key, m) : 0;
	(key == 24 || key == 27) ? key_z(key, m) : 0;
	(key == 123 || key == 126) ? key_move(key, m) : 0;
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	mlx_message(m);
	get_zyx(m);
	ft_horizon(m);
	ft_vertic(m);
	mlx_key_hook(m->win_ptr, keyfunction, m);
	mlx_loop(m->mlx_ptr);
	//ft_rotate(m);
	return (0);
}
