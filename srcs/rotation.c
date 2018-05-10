/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 23:58:20 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/10 13:56:38 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		rotation_x(t_env *m)
{
	float	y;
	float	z;
	int		i;
	int		j;

	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
		{
			y = m->pt_new[i][j].y;
			z = m->pt_new[i][j].z;
			m->pt_new[i][j].y = (y * cos(m->x_angle)) - (z * sin(m->x_angle));
			m->pt_new[i][j].z = (y * sin(m->x_angle)) + (z * cos(m->x_angle));
		}
	}
}

void		rotation_y(t_env *m)
{
	float	x;
	float	z;
	int		i;
	int		j;

	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
		{
			x = m->pt_new[i][j].x;
			z = m->pt_new[i][j].z;
			m->pt_new[i][j].x = (z * sin(m->y_angle)) + (x * cos(m->y_angle));
			m->pt_new[i][j].z = (z * cos(m->y_angle)) - (x * sin(m->y_angle));
		}
	}
}

void		rotation_z(t_env *m)
{
	float	x;
	float	y;
	int		i;
	int		j;

	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
		{
			x = m->pt_new[i][j].x;
			y = m->pt_new[i][j].y;
			m->pt_new[i][j].x = (x * cos(m->z_angle)) - (y * sin(m->z_angle));
			m->pt_new[i][j].y = (x * sin(m->z_angle)) + (y * cos(m->z_angle));
		}
	}
}

void		ft_rotate(t_env *m, int key)
{
	key == 7 || key == 9 ? rotation_x(m) : 0;
	key == 8 || key == 2 ? rotation_y(m) : 0;
	key == 6 || key == 0 ? rotation_z(m) : 0;
	key == 4 || key == 5 ? rotation_x(m) : 0;
	key == 6 || key == 7 ? rotation_y(m) : 0;
	m->x_angle = 0;
	m->y_angle = 0;
	m->z_angle = 0;
}
