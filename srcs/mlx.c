/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:19:07 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/10 14:16:03 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		init_struct(t_env *m)
{
	m->x_angle = 0;
	m->y_angle = 0;
	m->z_angle = 0;
	m->zoom = 1;
	m->x_move = 0;
	m->y_move = 0;
	m->z_move = 0;
	m->z_gap = 1.5;
	m->midx = m->x_max / 2;
	m->midy = m->y_max / 2;
}

void		mlx_message(t_env *m)
{
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 5, 0xFFFFFF, "[ESC] : EXIT");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 25, 0xFFFFFF,
			"X ROTATION : X, V");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 45, 0xFFFFFF,
			"Y ROTATION : C, D");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 65, 0xFFFFFF,
			"Z ROTATION : Z, A");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 85, 0xFFFFFF, "MOVE : ARROWS");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 105, 0xFFFFFF,
			"ZOOM IN/OUT : I, O");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 125, 0xFFFFFF, "Z : -, +");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 1455, 0xFFFFFF, "RESET : R");
}

void		midpoint(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
		{
			m->pt_new[i][j].x += ((m->win_x / 2) - (m->gap * m->midx));
			m->pt_new[i][j].y += ((m->win_y / 2) - (m->gap * m->midy));
		}
	}
}

void		mlx(t_env *m)
{
	mlx_message(m);
	key_color_1_x(m);
	prepare_pt(m);
	get_zxy(m);
	midpoint(m);
	ft_horizon(m);
	get_zyx(m);
	ft_vertic(m);
	mlx_mouse_hook(m->win_ptr, mousefunction, m);
	mlx_hook(m->win_ptr, 2, 0, keyfunction, m);
	mlx_loop(m->mlx_ptr);
}
