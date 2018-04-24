/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:19:07 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/23 18:43:54 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		mlx(t_env *m)
{
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, WIN_X, WIN_Y, "MOON");
	draw(m);
	mlx_key_hook(m->win_ptr, key_escape, 0);
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 5, 0x4876ff, "[ESC] : EXIT");
	mlx_loop(m->mlx_ptr);
}

int			key_escape(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}
