/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:18:40 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/08 22:43:58 by ksonu            ###   ########.fr       */
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
//			printf("30\n");
//			printf("i = %d	j = %d\n", i, j);
//			printf("y_max = %d	x_max = %d\n", m->y_max, m->x_max);
//			printf("m->pt[%d][%d].color = %d\n", i, j, m->pt[i][j].color);
//			printf("m->pt_new[%d][%d].color = %d\n", i, j, m->pt_new[i][j].color);
			if (m->pt[i][j].color != 0)
			{
//				printf("321\n");
				m->pt_new[i][j].color = m->pt[i][j].color;
			}
			else
			{
//				printf("987\n");
				m->pt_new[i][j].color = 0xFFFFFF;
			}
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
			if (m->pt_new[j][i].color != 0xFFFFFF)
				m->peter[i][j].color = m->pt_new[j][i].color;
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
			if (m->pt_new[i][j].z_tmp == 0 && m->pt_new[i][j + 1].z_tmp != 0)
				m->pt_new[i][j].color = 0xbf3eff; 
			else if (m->pt_new[i][j].z_tmp != 0 && m->pt_new[i][j + 1].z_tmp == 0)
				m->pt_new[i][j].color = 0xbf3eff;
			else if (m->pt_new[i][j].z_tmp != 0)
				m->pt_new[i][j].color = 0xff3e96;
			else if (m->pt_new[i][j].z_tmp == 0)
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
			if (m->peter[i][j].z_tmp == 0 && m->peter[i][j + 1].z_tmp != 0)
				m->peter[i][j].color = 0xbf3eff; 
			else if (m->peter[i][j].z_tmp != 0 && m->peter[i][j + 1].z_tmp == 0)
				m->peter[i][j].color = 0xbf3eff;
			else if (m->peter[i][j].z_tmp != 0)
				m->peter[i][j].color = 0xff3e96;
			else if (m->peter[i][j].z_tmp == 0)
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
			if (m->pt_new[i][j].z_tmp == 0 && m->pt_new[i][j + 1].z_tmp != 0)
				m->pt_new[i][j].color = 0xA020F0; 
			else if (m->pt_new[i][j].z_tmp != 0 && m->pt_new[i][j + 1].z_tmp == 0)
				m->pt_new[i][j].color = 0xA020F0;
			else if (m->pt_new[i][j].z_tmp != 0)
				m->pt_new[i][j].color = 0xFF6EB4;
			else if (m->pt_new[i][j].z_tmp == 0)
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
			if (m->peter[i][j].z_tmp == 0 && m->peter[i][j + 1].z_tmp != 0)
				m->peter[i][j].color = 0xA020F0; 
			else if (m->peter[i][j].z_tmp != 0 && m->peter[i][j + 1].z_tmp == 0)
				m->peter[i][j].color = 0xA020F0;
			else if (m->peter[i][j].z_tmp != 0)
				m->peter[i][j].color = 0xFF6EB4;
			else if (m->peter[i][j].z_tmp == 0)
				m->peter[i][j].color = 0x87CEFA;
		}
	}
}
