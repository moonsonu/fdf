/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 23:58:20 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/06 21:55:18 by ksonu            ###   ########.fr       */
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
			y = m->pt_new[i][j].y_tmp;
			z = m->pt_new[i][j].z_tmp;
			m->pt_new[i][j].y_tmp = (y * cos(m->x_angle)) - (z * sin(m->x_angle));
			m->pt_new[i][j].z_tmp = (y * sin(m->x_angle)) + (z * cos(m->x_angle));
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
			x = m->pt_new[i][j].x_tmp;
			z = m->pt_new[i][j].z_tmp;
			m->pt_new[i][j].x_tmp = (z * sin(m->y_angle)) + (x * cos(m->y_angle));
			m->pt_new[i][j].z_tmp = (z * cos(m->y_angle)) - (x * sin(m->y_angle));
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
			x = m->pt_new[i][j].x_tmp;
			y = m->pt_new[i][j].y_tmp;
			m->pt_new[i][j].x_tmp = (x * cos(m->z_angle)) - (y * sin(m->z_angle));
			m->pt_new[i][j].y_tmp = (x * sin(m->z_angle)) + (y * cos(m->z_angle));
		}
	}
}

void		ft_rotate(t_env *m)
{
	rotation_x(m);
	rotation_y(m);
	rotation_z(m);
}
