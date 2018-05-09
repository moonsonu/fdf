/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousefunction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 21:12:54 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/07 20:15:09 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*int			mousefunction(int button, int x, int y, t_env *m)
{
	int		i;
	int		j;
	(void)x;
	(void)y;
	if (button == 4)
	{
		printf("4\n");
		m->gap += 10;
	}
	if (button == 5)
	{
		printf("5\n");
		m->gap -= 10;
	}
	if (button == 6)
	{
		printf("6\n");
		m->y_angle += .1;
	}
	if (button == 7)
	{
		printf("7\n");
		m->y_angle -= .1;
	}
	if (button == 1)
	{
		printf("1\n");
		i = 0;
		j = 0;
		m->pt[i][j].color *= 1297;
		printf("color[%d] i[%d] j[%d]\n", m->pt[i][j].color, i, j);
		i++; 
		j++;
		//m->color += 307;
	}
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	mlx_message(m);
	ft_rotate(m);
	get_zyx(m);
	ft_horizon(m);
	ft_vertic(m);
	mlx_loop(m->mlx_ptr);
	return (0);
}*/
