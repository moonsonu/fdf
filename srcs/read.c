/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:52:57 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/23 21:13:43 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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
		tmp = ft_wdcount(line, ' ');
		if (m->x_max != 0 && tmp != m->x_max)
		{
			ft_putstr("error");
			return (1);
		}
		m->x_max = tmp;
		ft_strdel(&line);
	}
	if (m->x_max > m->y_max)
		m->gap = (WIN_X - 200) / m->x_max;
	else if (m->x_max < m->y_max)
		m->gap = (WIN_Y - 200) / m->y_max;
	return (0);
}

void		read_value(int fd, t_env *m)
{
	char	*line;
	char	**split;
	int		i;
	int		j;

	i = 0;
	m->midx = m->x_max / 2;
	m->midy = m->y_max / 2;
	m->pt = (t_point**)malloc(sizeof(t_point*) * (m->y_max + 1));
	while (i < m->y_max + 1)
	{
		if (get_next_line(fd, &line) == 1)
		{
			m->pt[i] = (t_point*)malloc(sizeof(t_point) * (m->x_max + 1));
			ft_bzero(m->pt[i], (sizeof(t_point) * m->x_max + 1));
			split = ft_strsplit(line, ' ');
			j = 0;
			while (j < m->x_max + 1 && split[j])
			{
				m->pt[i][j].y = (((i - m->midy) * m->gap) + (WIN_Y / 2));
				m->pt[i][j].x = (((j - m->midx) * m->gap) + (WIN_X / 2));
				m->pt[i][j].z = ft_atoi(split[j]);
				j++;
			}
			ft_splitdel(split);
			ft_strdel(&line);
		}
		i++;
	}
	m->peter = (t_point**)malloc(sizeof(t_point*) * (m->x_max + 1));
	i = 0;
	while (i < m->x_max + 1)
	{
		m->peter[i] = (t_point*)malloc(sizeof(t_point) * (m->y_max + 1));
		i++;
	}
}
