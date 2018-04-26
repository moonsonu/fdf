/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 00:06:28 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/24 21:15:19 by ksonu            ###   ########.fr       */
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
	key == 27 ? m->z_gap -= 10 : 0;
	key == 24 ? m->z_gap += 10 : 0;
}

int			key_board(int key, t_env *m)
{
	key == 53 ? key_escape(key) : 0;
	(key >= 6 && key <= 9) || key == 0 || key == 2 ? key_rot(key, m) : 0;
	(key == 24 || key == 27) ? key_z(key, m) : 0;
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	ft_horizon(m);
	ft_rotate(m);
	ft_vertic(m);
	mlx(m);
	mlx_message(m);
	return (0);
}
