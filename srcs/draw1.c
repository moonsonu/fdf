/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:33:48 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/23 20:28:05 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		draw_x(t_env *m, t_point pt1, t_point pt2)
{
	int		k;

	k = 0;
	while (pt1.x + k <= pt2.x)
	{
		if (pt1.y == pt2.y)
			mlx_pixel_put(m->mlx_ptr, m->win_ptr, pt1.x + k, pt1.y, 0xFFFFFF);
		else if (pt1.y != pt2.y)
		{
			mlx_pixel_put(m->mlx_ptr, m->win_ptr, (pt1.x + k), ((pt2.y - pt1.y) / (pt2.x - pt1.x) * ((pt1.x + k) - pt1.x) + pt1.y), 0xFFFFFF); 
		}
		k++;
	}
}

void		draw_y(t_env *m, t_point pt1, t_point pt2)
{
	int		k;

	k = 0;
	while (pt1.y + k <= pt2.y)
	{
		if (pt1.x == pt2.x)
			mlx_pixel_put(m->mlx_ptr, m->win_ptr, pt1.x, pt1.y + k, 0xFFFFFF);
		else if (pt1.x != pt2.x)
		{
			mlx_pixel_put(m->mlx_ptr, m->win_ptr, ((pt1.y + k) - pt1.y) / (pt2.y - pt1.y) * ((pt2.x - pt1.x) + pt1.x), (pt1.y + k), 0xFFFFFF); 
		}
		k++;
	}
}

void		draw(t_env *m)
{
	int		i;
	int		j;

	i = 0;
	while (i < m->y_max)
	{
		j = 0;
		while (j < m->x_max - 1)
		{
			if (m->pt[i][j].z != 0)
			{
				m->pt[i][j].x += m->pt[i][j].x + (m->gap * 1.1);
				m->pt[i][j].y -= m->pt[i][j].y + (m->gap * 1.1);
			}
			draw_x(m, m->pt[i][j], m->pt[i][j + 1]);
			//draw_x(m, m->pt[i][j], m->pt[i + 1][j]);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < m->x_max)
	{
		i = 0;
		while (i < m->y_max - 1)
		{
			draw_y(m, m->pt[i][j], m->pt[i + 1][j]);
			i++;
		}
		j++;
	}
}
