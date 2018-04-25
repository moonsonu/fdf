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

int		key_rot_x(int key, t_env *m)
{
	//x7 v9 c8 d2 z6 a0 
	if (key == 7)
	{
		m->x_angle -= 0.01;
		return (0);
	}
	else if (key == 9)
	{
		m->x_angle += 0.01;
		return (0);
	}
	return (1);
}
int		key_rot_y(int key, t_env *m)
{
	if (key == 8)
	{
		m->y_angle -= 0.01;
		return (0);
	}
	else if (key == 2)
	{
		m->y_angle += 0.01;
		return (0);
	}
	return (1);
}

int		key_rot_z(int key, t_env *m)
{
	if (key == 6)
	{
		m->z_angle -= 0.01;
		return (0);
	}
	else if (key == 0)
	{
		m->z_angle += 0.01;
		return (0);
	}
	return (1);
}

int		key_z(int key, t_env *m)
{
	//27minus 24equal
	if (key == 27)
	{
		m->z_gap -= 10;
		return (0);
	}
	else if (key == 24)
	{
		m->z_gap += 10;
		return (0);
	}
	return (1);
}

int		key_board(int key, t_env *m)
{
	if (key == 53)
		key_escape(key);
	if ((key >= 6 && key <= 9) || key == 0 || key == 2)
	{
		mlx_clear_window(m->mlx_ptr, m->win_ptr);
		key_rot_x(key, m);
		key_rot_y(key, m);
		key_rot_z(key, m);
		ft_rotate(m);
		mlx(m);
		return (0);
	}
	if (key == 24 || key == 27)
	{
		mlx_clear_window(m->mlx_ptr, m->win_ptr);
		key_z(key, m);
		mlx(m);
	}
	return (0);
}
