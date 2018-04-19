/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:52:57 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/19 16:31:49 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		read_max(int fd, t_env *m)
{
	char	*line;
	m->y_max = 0;
	m->x_max = 0;
		while (get_next_line(fd, &line) > 0)
		{
			m->y_max++;
			m->x_max = ft_wdcount(line, ' ');
			ft_strdel(&line);
		}
}

void		read_value(int fd, t_env *m)
{
	char	*line;
	char	**split;
	int		i;
	int		j;
	
	i = 0;
	m->pt = (t_point**)malloc(sizeof(t_point*) * (m->y_max + 1));
	while (i < m->y_max)
	{
		if (get_next_line(fd, &line) == 1)
		{
			m->pt[i] = (t_point*)malloc(sizeof(t_point) * (m->x_max + 1));
			split = ft_strsplit(line, ' ');
			j = 0;
			while (j < m->x_max && split[j])
			{
				m->pt[i][j].x = ft_atoi(split[j]);
				printf("m->pt[%d][%d].x : [%d]\n", i, j, m->pt[i][j].x);
				j++;
			}
			ft_splitdel(split);
			ft_strdel(&line);
		}
		i++;
	}
}
