/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 22:06:09 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/26 16:59:05 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		ft_draw_x(t_env *m, int i, int j)
{
	float	k;
	float	l;

	k = m->pt[i][j].x;
	l = m->pt[i][j].y;
	while (++k < m->pt[i][j + 1].x)
	{
		mlx_pixel_put(m->mlx_ptr, m->win_ptr, k, ((k - m->pt[i][j].x) /
					(m->pt[i][j + 1].x - m->pt[i][j].x) * (m->pt[i][j + 1].y -
						m->pt[i][j].y) + m->pt[i][j].y), 0xFFFFFF);
	}
	while (++l < m->pt[i][j + 1].y)
	{
		mlx_pixel_put(m->mlx_ptr, m->win_ptr, ((l - m->pt[i][j].y) /
					(m->pt[i][j + 1].y - m->pt[i][j].y) * (m->pt[i][j + 1].x -
						m->pt[i][j].x) + m->pt[i][j].x), l, 0xFFFFFF);	
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
			if (m->pt[i][j].z != 0)
			{
				m->pt[i][j].x = m->pt[i][j].x + (m->z_gap);
				m->pt[i][j].y = m->pt[i][j].y - (m->z_gap);
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
