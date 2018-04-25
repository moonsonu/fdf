/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 23:58:20 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/24 19:33:40 by ksonu            ###   ########.fr       */
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
			y = m->pt[i][j].y;
			z = m->pt[i][j].z;
			m->pt[i][j].y = (y * cos(m->x_angle)) - (z * sin(m->x_angle));
			m->pt[i][j].z = (y * sin(m->x_angle)) + (z * cos(m->x_angle));
			y = m->peter[i][j].y;
			z = m->peter[i][j].z;
			m->peter[i][j].y = (y * cos(m->x_angle)) - (z * sin(m->x_angle));
			m->peter[i][j].z = (y * sin(m->x_angle)) + (z * cos(m->x_angle));
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
			x = m->pt[i][j].x;
			z = m->pt[i][j].z;
			m->pt[i][j].x = (z * sin(m->y_angle)) - (x * cos(m->y_angle));
			m->pt[i][j].z = (z * cos(m->y_angle)) + (x * sin(m->y_angle));
			x = m->peter[i][j].x;
			z = m->peter[i][j].z;
			m->peter[i][j].x = (z * sin(m->y_angle)) - (x * cos(m->y_angle));
			m->peter[i][j].z = (z * cos(m->y_angle)) + (x * sin(m->y_angle));
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
			x = m->pt[i][j].x;
			y = m->pt[i][j].y;
			m->pt[i][j].x = (x * cos(m->z_angle)) - (y * sin(m->z_angle));
			m->pt[i][j].y = (x * sin(m->z_angle)) + (y * cos(m->z_angle));
			x = m->peter[i][j].x;
			y = m->peter[i][j].y;
			m->peter[i][j].x = (x * cos(m->z_angle)) - (y * sin(m->z_angle));
			m->peter[i][j].y = (x * sin(m->z_angle)) + (y * cos(m->z_angle));
		}
	}
}

void		ft_rotate(t_env *m)
{
	rotation_x(m);
	rotation_y(m);
	rotation_z(m);
}
