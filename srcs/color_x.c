/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:05:20 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/10 14:10:49 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		key_color_1_x(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
		{
			if (m->pt[i][j].color != 0)
				m->pt_new[i][j].color = m->pt[i][j].color;
			else
				m->pt_new[i][j].color = 0xFFFFFF;
		}
	}
	key_color_1_y(m);
}

void		key_color_2_x(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
		{
			if (m->pt_new[i][j].z_tmp == 0 && m->pt_new[i][j + 1].z_tmp != 0)
				m->pt_new[i][j].color = 0xbf3eff;
			else if (m->pt_new[i][j].z_tmp != 0 &&
					m->pt_new[i][j + 1].z_tmp == 0)
				m->pt_new[i][j].color = 0xbf3eff;
			else if (m->pt_new[i][j].z_tmp != 0 && m->pt_new[i][j].z_tmp <
					m->pt_new[i][j + 1].z_tmp)
				m->pt_new[i][j].color = 0x41d4ff;
			else if (m->pt_new[i][j].z_tmp != 0)
				m->pt_new[i][j].color = 0xff3e96;
			else if (m->pt_new[i][j].z_tmp == 0)
				m->pt_new[i][j].color = 0xffaeb9;
		}
	}
	key_color_2_y(m);
}

void		key_color_3_x(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->y_max)
	{
		j = -1;
		while (++j < m->x_max)
		{
			if (m->pt_new[i][j].z_tmp == 0 && m->pt_new[i][j + 1].z_tmp != 0)
				m->pt_new[i][j].color = 0xA020F0;
			else if (m->pt_new[i][j].z_tmp != 0 &&
					m->pt_new[i][j + 1].z_tmp == 0)
				m->pt_new[i][j].color = 0xA020F0;
			else if (m->pt_new[i][j].z_tmp != 0 && m->pt_new[i][j].z_tmp <
					m->pt_new[i][j + 1].z_tmp)
				m->pt_new[i][j].color = 0xd6ff00;
			else if (m->pt_new[i][j].z_tmp != 0)
				m->pt_new[i][j].color = 0xFF6EB4;
			else if (m->pt_new[i][j].z_tmp == 0)
				m->pt_new[i][j].color = 0x87CEFA;
		}
	}
	key_color_3_y(m);
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
			m->pt_new[i][j].color *= 1297;
			m->pt_new[i][j].color += 307;
		}
	}
	i = -1;
	while (++i < m->x_max)
	{
		j = -1;
		while (++j < m->y_max)
		{
			m->peter[i][j].color *= 1297;
			m->peter[i][j].color += 307;
		}
	}
}
