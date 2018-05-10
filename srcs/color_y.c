/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_y.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <ksonu@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:05:00 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/10 14:10:51 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		key_color_1_y(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->x_max)
	{
		j = -1;
		while (++j < m->y_max)
		{
			if (m->pt_new[j][i].color != 0xFFFFFF)
				m->peter[i][j].color = m->pt_new[j][i].color;
			else
				m->peter[i][j].color = 0xFFFFFF;
		}
	}
}

void		key_color_2_y(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->x_max)
	{
		j = -1;
		while (++j < m->y_max)
		{
			if (m->peter[i][j].z_tmp == 0 && m->peter[i][j + 1].z_tmp != 0)
				m->peter[i][j].color = 0xbf3eff;
			else if (m->peter[i][j].z_tmp != 0 && m->peter[i][j + 1].z_tmp == 0)
				m->peter[i][j].color = 0xbf3eff;
			else if (m->peter[i][j].z_tmp != 0 && m->peter[i][j].z_tmp <
					m->peter[i][j + 1].z_tmp)
				m->peter[i][j].color = 0x41d4ff;
			else if (m->peter[i][j].z_tmp != 0)
				m->peter[i][j].color = 0xff3e96;
			else if (m->peter[i][j].z_tmp == 0)
				m->peter[i][j].color = 0xffaeb9;
		}
	}
}

void		key_color_3_y(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->x_max)
	{
		j = -1;
		while (++j < m->y_max)
		{
			if (m->peter[i][j].z_tmp == 0 && m->peter[i][j + 1].z_tmp != 0)
				m->peter[i][j].color = 0xA020F0;
			else if (m->peter[i][j].z_tmp != 0 && m->peter[i][j + 1].z_tmp == 0)
				m->peter[i][j].color = 0xA020F0;
			else if (m->peter[i][j].z_tmp != 0 && m->peter[i][j].z_tmp <
					m->peter[i][j + 1].z_tmp)
				m->peter[i][j].color = 0xd6ff00;
			else if (m->peter[i][j].z_tmp != 0)
				m->peter[i][j].color = 0xFF6EB4;
			else if (m->peter[i][j].z_tmp == 0)
				m->peter[i][j].color = 0x87CEFA;
		}
	}
}
