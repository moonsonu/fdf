/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:33:48 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/19 21:59:57 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw(t_env *m, t_point **new)
{
	int		i;
	int		j;


	i = 0;
	while (i < m->y_max)
	{
		mlx_pixel_put(m->mlx_ptr, m->win_ptr, new[i][j].y, 
				new[i][j].x, 0xFFFFFF);
		j = 0;
		while (j < m->x_max)
		{
			mlx_pixel_put(m->mlx_ptr, m->win_ptr, new[i][j].y, 
					new[i][j].x, 0xFFFFFF);
			j++;
		}
		i++;
	}
}
