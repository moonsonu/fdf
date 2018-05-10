/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 22:06:09 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/10 14:14:53 by ksonu            ###   ########.fr       */
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
			m->pt_new[i][j].x = ((m->pt_new[i][j].x_tmp) * m->gap);
			m->pt_new[i][j].y = ((m->pt_new[i][j].y_tmp) * m->gap);
			m->pt_new[i][j].z = m->pt_new[i][j].z_tmp;
		}
	}
}

void		get_zxy(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
		{
			m->pt_new[i][j].x = m->pt_new[i][j].x + m->x_move;
			m->pt_new[i][j].y = m->pt_new[i][j].y + m->y_move;
			if (m->pt[i][j].z != 0)
			{
				m->pt_new[i][j].x += (m->pt_new[i][j].z_tmp * m->z_gap);
				m->pt_new[i][j].y -= (m->pt_new[i][j].z_tmp * m->z_gap);
			}
		}
	}
	m->x_move = 0;
	m->y_move = 0;
	m->z_move = 0;
	m->z_gap = 0;
}

void		ft_horizon(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
			ft_draw_x(m, i, j);
	}
}
