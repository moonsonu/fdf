/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:33:48 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/23 21:26:12 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		draw_x(t_env *m, int i, int j, float k, float l)
{
	while (k < m->pt[i][j + 1].x)
	{
		mlx_pixel_put(m->mlx_ptr, m->win_ptr, k, ((k - m->pt[i][j].x) / (m->pt[i][j + 1].x - m->pt[i][j].x) * (m->pt[i][j + 1].y - m->pt[i][j].y) + m->pt[i][j].y), 0xFFFFFF);
		k++;
	}
	while (l < m->pt[i][j + 1].y)
	{
		mlx_pixel_put(m->mlx_ptr, m->win_ptr, ((l - m->pt[i][j].y) / (m->pt[i][j + 1].y - m->pt[i][j].y) * (m->pt[i][j + 1].x - m->pt[i][j].x) + m->pt[i][j].x), l, 0xFFFFFF);
		l++;
	}
}

void		draw_y(t_env *m, int i, int j, float k, float l)
{
	while (k < m->peter[i][j + 1].x)
	{
		mlx_pixel_put(m->mlx_ptr, m->win_ptr, k, ((k - m->peter[i][j].x) / (m->peter[i][j + 1].x - m->peter[i][j].x) * (m->peter[i][j + 1].y - m->peter[i][j].y) + m->peter[i][j].y), 0xFFFFFF);
		k++;
	}
	while (l < m->peter[i][j + 1].y)
	{
		mlx_pixel_put(m->mlx_ptr, m->win_ptr, ((l - m->peter[i][j].y) / (m->peter[i][j + 1].y - m->peter[i][j].y) * (m->peter[i][j + 1].x - m->peter[i][j].x) + m->peter[i][j].x), l, 0xFFFFFF);
		l++;
	}
}

void		draw(t_env *m)
{
	int		i;
	int		j;
	float		k;
	float		l;

	i = 0;
	while (i < m->y_max)
	{
		j = 0;
		while (j < m->x_max - 1)
		{
			if (m->pt[i][j].z != 0)
			{
				m->pt[i][j].x = m->pt[i][j].x + (m->gap * 1.3);
				m->pt[i][j].y = m->pt[i][j].y - (m->gap * 1.9);
			}
			mlx_pixel_put(m->mlx_ptr, m->win_ptr, m->pt[i][j].x, m->pt[i][j].y, 0xFFFFFF);
			j++;
		}
		i++;
	}
	i = -1;
	while (++i <= m->x_max)
	{
		j = -1;
		while (++j < m->y_max)
		{
			m->peter[i][j].x = m->pt[j][i].x;
			m->peter[i][j].y = m->pt[j][i].y;
			m->peter[i][j].z = m->pt[j][i].z;
		}
	}
	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j <= m->x_max)
		{
			k = m->pt[i][j].x;
			l = m->pt[i][j].y;
			draw_x(m, i, j, k, l);
		}
	}
	i = -1;
	while (++i <= m->x_max)
	{
		j = -1;
		while (++j < m->y_max)
		{
			k = m->peter[i][j].x;
			l = m->peter[i][j].y;
			draw_y(m, i, j, k, l);
		}
	}
}
