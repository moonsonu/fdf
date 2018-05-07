/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:52:57 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/06 22:48:51 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		read_dup(t_env *m)
{
	int		i;
	int		j;

	m->zoom = 10;
	i = -1;
	m->pt_new = (t_point**)malloc(sizeof(t_point*) * (m->x_max + 1));
	while (++i < m->y_max)
	{
		j = -1;
		m->pt_new[i] = (t_point*)malloc(sizeof(t_point) * (m->x_max + 1));
		while (++j < m->x_max)
		{
			m->pt_new[i][j].x_tmp = m->pt[i][j].x;
			m->pt_new[i][j].y_tmp = m->pt[i][j].y;
			prepare_zscale(m, m->pt[i][j]);
			m->pt_new[i][j].z_tmp = m->pt[i][j].z;
			m->pt_new[i][j].color = m->pt[i][j].color;

		}
	}
}

void		read_color(char **str, t_env *m, int i, int j)
{
	char	*ptr;
	char	*tmp;

	if ((ptr = ft_strchr(str[j], ',')))
	{
		tmp = ft_strdup(ptr + 3);
		m->pt[i][j].color = ft_atoi_base(tmp, 16);
	}
	else
		m->pt[i][j].color = 0;
}

void		malloc_p(t_env *m)
{
	int		i;

	m->pt = (t_point**)malloc(sizeof(t_point*) * (m->y_max + 1));
	m->peter = (t_point**)malloc(sizeof(t_point*) * (m->x_max + 1));
	i = -1;
	while (++i < m->y_max + 1)
		m->pt[i] = (t_point*)malloc(sizeof(t_point) * (m->x_max + 1));
	i = -1;
	while (++i < m->x_max + 1)
		m->peter[i] = (t_point*)malloc(sizeof(t_point) * (m->y_max + 1));
}

int			read_max(int fd, t_env *m)
{
	char	*line;
	int		tmp;

	tmp = 0;
	m->y_max = 0;
	m->x_max = 0;
	while (get_next_line(fd, &line) > 0)
	{
		m->y_max++;
		tmp = ft_wdcount(line, ' ') + 1;
		if (m->x_max != 0 && tmp != m->x_max)
		{
			ft_putstr("error");
			return (1);
		}
		m->x_max = tmp;
		ft_strdel(&line);
	}
	if (m->x_max >= m->y_max)
		m->gap = (WIN_X / 3) / m->x_max;
	else if (m->x_max < m->y_max)
		m->gap = (WIN_Y / 3) / m->y_max;
	return (0);
}

void		read_value(int fd, t_env *m)
{
	char	*line;
	char	**split;
	int		i;
	int		j;

	i = -1;
	m->midx = m->x_max / 2;
	m->midy = m->y_max / 2;
	malloc_p(m);
	while (++i < m->y_max + 1)
	{
		if (get_next_line(fd, &line) == 1)
		{
			split = ft_strsplit(line, ' ');
			j = -1;
			while (++j < m->x_max + 1 && split[j])
			{
				read_color(split, m, i, j);
				m->pt[i][j].y = i;
				m->pt[i][j].x = j;
				m->pt[i][j].z = ft_atoi(split[j]);
			}
			ft_splitdel(split);
			ft_strdel(&line);
		}
	}
	read_dup(m);
}
