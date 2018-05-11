/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:52:57 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/10 21:09:08 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		read_dup(t_env *m)
{
	int		i;
	int		j;

	i = -1;
	m->pt_new = (t_point**)malloc(sizeof(t_point*) * (m->y_max + 1));
	while (++i < m->y_max)
	{
		j = -1;
		m->pt_new[i] = (t_point*)malloc(sizeof(t_point) * (m->x_max + 1));
		while (++j < m->x_max)
		{
			m->pt_new[i][j].x_tmp = m->pt[i][j].x;
			m->pt_new[i][j].y_tmp = m->pt[i][j].y;
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
		free(tmp);
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
	m->window = m->win_x;
	while (get_next_line(fd, &line) > 0)
	{
		/*if (validation(line) == 1)
			ft_putendl("Invalid map\n");*/
		m->y_max++;
		tmp = ft_wdcount(line, ' ') + 1;
		if (m->x_max < tmp)
			m->x_max = tmp;
		ft_strdel(&line);
	}
	if (m->x_max >= m->y_max)
		m->gap = (m->win_x / 2) / m->x_max + 1;
	else if (m->x_max < m->y_max)
		m->gap = (m->win_y / 2) / m->y_max + 1;
	close(fd);
	return (0);
}

void		read_value(int fd, t_env *m)
{
	char	*line;
	char	**split;
	int		i;
	int		j;

	i = -1;
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
	close(fd);
	read_dup(m);
}
