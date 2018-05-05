/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:19:07 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/04 17:16:15 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		init_struct(t_env *m)
{
	m->x_angle = 0;
	m->y_angle = 0;
	m->z_angle = 0;
	m->z_gap = 0;
	m->x_move = 0;
	m->y_move = 0;

}

void		mlx_message(t_env *m)
{

	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 5, 0xFFFFFF, "[ESC] : EXIT");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 680, 0xFFFFFF, "X ROTATION : X, V");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 700, 0xFFFFFF, "Y ROTATION : C, D");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 720, 0xFFFFFF, "Z ROTATION : Z, A");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 1000, 700, 0xFFFFFF, "MOVE : ARROWS");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 1000, 720, 0xFFFFFF, "ZOOM IN/OUT : I, O");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 550, 700, 0xFFFFFF, "Z : -, +");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 550, 720, 0xFFFFFF, "RESET : R");
}

void		mlx(t_env *m)
{
	mlx_message(m);
	key_color_1_x(m);
	get_zxy(m);
	ft_horizon(m);
	get_zyx(m);
	ft_vertic(m);
	mlx_mouse_hook(m->win_ptr, mousefunction, m);
	mlx_key_hook(m->win_ptr, keyfunction, m);
	mlx_loop(m->mlx_ptr);
}
