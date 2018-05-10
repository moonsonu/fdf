/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_y.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 21:52:44 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/09 17:29:58 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		ft_draw_y(t_env *m, int i, int j)
{
	float	k;
	float	l;

	k = m->peter[i][j].x;
	l = m->peter[i][j].y;
	while (++k < m->peter[i][j + 1].x)
	{
		mlx_pixel_put(m->mlx_ptr, m->win_ptr, k, ((k - m->peter[i][j].x) /
					(m->peter[i][j + 1].x - m->peter[i][j].x) *
					(m->peter[i][j + 1].y - m->peter[i][j].y) +
					m->peter[i][j].y), m->peter[i][j].color);
	}
	while (++l < m->peter[i][j + 1].y)
	{
		mlx_pixel_put(m->mlx_ptr, m->win_ptr, ((l - m->peter[i][j].y) /
					(m->peter[i][j + 1].y - m->peter[i][j].y) *
					(m->peter[i][j + 1].x - m->peter[i][j].x) +
					m->peter[i][j].x), l, m->peter[i][j].color);
	}
}

void		get_zyx(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->x_max)
	{
		j = -1;
		while (++j < m->y_max)
		{
			m->peter[i][j].x = m->pt_new[j][i].x;
			m->peter[i][j].y = m->pt_new[j][i].y;
			m->peter[i][j].z = m->pt_new[j][i].z;
			m->peter[i][j].z_tmp = m->pt_new[j][i].z_tmp;
		}
	}
}

void		ft_vertic(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->x_max)
	{
		j = -1;
		while (++j < m->y_max)
			ft_draw_y(m, i, j);
	}
}
