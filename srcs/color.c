/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:18:40 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/06 19:27:22 by ksonu            ###   ########.fr       */
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
			if (m->pt[j][i].color != 0)
				m->peter[i][j].color = m->pt[i][j].color;
			else
				m->peter[i][j].color = 0xFFFFFF;
		}
	}
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
			if (m->pt_new[i][j].z == 0 && m->pt_new[i][j + 1].z != 0)
				m->pt_new[i][j].color = 0xbf3eff; 
			else if (m->pt_new[i][j].z != 0 && m->pt_new[i][j + 1].z == 0)
				m->pt_new[i][j].color = 0xbf3eff;
			else if (m->pt_new[i][j].z != 0)
				m->pt_new[i][j].color = 0xff3e96;
			else if (m->pt_new[i][j].z == 0)
				m->pt_new[i][j].color = 0xffaeb9;
		}
	}
	key_color_2_y(m);
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
			if (m->peter[i][j].z == 0 && m->peter[i][j + 1].z != 0)
				m->peter[i][j].color = 0xbf3eff; 
			else if (m->peter[i][j].z != 0 && m->peter[i][j + 1].z == 0)
				m->peter[i][j].color = 0xbf3eff;
			else if (m->peter[i][j].z != 0)
				m->peter[i][j].color = 0xff3e96;
			else if (m->peter[i][j].z == 0)
				m->peter[i][j].color = 0xffaeb9;
		}
	}
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
			if (m->pt_new[i][j].z == 0 && m->pt_new[i][j + 1].z != 0)
				m->pt_new[i][j].color = 0xA020F0; 
			else if (m->pt_new[i][j].z != 0 && m->pt_new[i][j + 1].z == 0)
				m->pt_new[i][j].color = 0xA020F0;
			else if (m->pt_new[i][j].z != 0)
				m->pt_new[i][j].color = 0xFF6EB4;
			else if (m->pt_new[i][j].z == 0)
				m->pt_new[i][j].color = 0x87CEFA;
		}
	}
	key_color_3_y(m);
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
			if (m->peter[i][j].z == 0 && m->peter[i][j + 1].z != 0)
				m->peter[i][j].color = 0xA020F0; 
			else if (m->peter[i][j].z != 0 && m->peter[i][j + 1].z == 0)
				m->peter[i][j].color = 0xA020F0;
			else if (m->peter[i][j].z != 0)
				m->peter[i][j].color = 0xFF6EB4;
			else if (m->peter[i][j].z == 0)
				m->peter[i][j].color = 0x87CEFA;
		}
	}
}
