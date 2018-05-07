/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 22:06:09 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/06 22:47:23 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		ft_draw_x(t_env *m, int i, int j)
{
	float	k;
	float	l;

	k = m->pt_new[i][j].x;
	l = m->pt_new[i][j].y;
	while (++k < m->pt_new[i][j + 1].x)
	{
		mlx_pixel_put(m->mlx_ptr, m->win_ptr, k, ((k - m->pt_new[i][j].x) /
					(m->pt_new[i][j + 1].x - m->pt_new[i][j].x) *
					(m->pt_new[i][j + 1].y - m->pt_new[i][j].y) +
					m->pt_new[i][j].y), m->pt_new[i][j].color);
	}
	while (++l < m->pt_new[i][j + 1].y)
	{
		mlx_pixel_put(m->mlx_ptr, m->win_ptr, ((l - m->pt_new[i][j].y) / 
					(m->pt_new[i][j + 1].y - m->pt_new[i][j].y) * 
					(m->pt_new[i][j + 1].x - m->pt_new[i][j].x) + 
					m->pt_new[i][j].x), l, m->pt_new[i][j].color);
	}
}

void		prepare_pt(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
		{
			m->pt_new[i][j].x = ((m->pt_new[i][j].x_tmp - m->midx) * (m->zoom < 0 ? 0 : m->zoom)) + (WIN_X / 2);
			m->pt_new[i][j].y = ((m->pt_new[i][j].y_tmp - m->midy) * (m->zoom < 0 ? 0 : m->zoom)) + (WIN_Y / 2);
			m->pt_new[i][j].z = m->pt_new[i][j].z_tmp;
			printf("zoom[%d]\n", m->zoom);
		}
	}
}

void		get_zxy(t_env *m)
{
	int		i;
	int		j;

	m->z_gap = m->z_max - m->z_min;
	m->z_min = 0;
	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
		{
			m->pt_new[i][j].x += m->x_move;
			m->pt_new[i][j].y += m->y_move; 
			if (m->pt[i][j].z != 0)
			{
				m->pt_new[i][j].x += (m->z_gap);
				m->pt_new[i][j].y -= (m->z_gap);
			}
		}
	}
}

void		ft_horizon(t_env *m)
{
	int		i;
	int		j;

//	get_zxy(m);
	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
			ft_draw_x(m, i, j);
	}
}
