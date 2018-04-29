/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:18:40 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/28 21:10:38 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		key_color_1(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
		{
			if (m->pt_new[i][j].z != 0)
				m->pt_new[i][j].color = 0x00BFFF;
			m->pt_new[i][j].color = 0xFF1493;
		}
	}
}

void		key_color_2(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
		{
			if (m->pt_new[i][j].z != 0)
				m->pt_new[i][j].color = 0x87CEFA;
			m->pt_new[i][j].color = 0xFF6EB4;
		}
	}
}

void		key_color_3(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
		{
			if (m->pt_new[i][j].z != 0)
				m->pt_new[i][j].color = 0x990000;
			m->pt_new[i][j].color = 0x3399FF;
		}
	}
}

void		key_color_4(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
		{
			if (m->pt_new[i][j].z != 0)
				m->pt_new[i][j].color = 0xA020F0;
			m->pt_new[i][j].color = 0xAB82FF;
		}
	}
}
