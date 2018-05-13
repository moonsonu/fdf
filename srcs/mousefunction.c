/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousefunction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 21:12:54 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/12 18:10:51 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int			mousefunction(int button, int x, int y, t_env *m)
{
	(void)x;
	(void)y;
	if (button == 4)
		m->x_angle += M_PI / 30;
	if (button == 5)
		m->x_angle -= M_PI / 30;
	if (button == 6)
		m->y_angle += M_PI / 30;
	if (button == 7)
		m->y_angle -= M_PI / 30;
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	mlx_message(m);
	ft_rotate(m, button);
	get_zyx(m);
	ft_horizon(m);
	ft_vertic(m);
	mlx_loop(m->mlx_ptr);
	return (0);
}
