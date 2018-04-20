/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:16:23 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/19 21:59:59 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_point			**set_middle(t_env *m)
{
	t_point		**new;
	int			i;
	int			j;

	i = 0;
	new = (t_point**)malloc(sizeof(t_point*) * (m->y_max + 1));
	m->midx = m->x_max / 2;
	m->midy = m->y_max / 2;
	while (i < m->y_max)
	{
		new[i] = (t_point*)malloc(sizeof(t_point) * (m->x_max + 1));
		j = 0;
		while (j < m->x_max)
		{
			printf("m->x_max[%d] j[%d]\n", m->x_max, j);
			new[i][j].y = ((i - m->midy) * m->gap);
			new[i][j].x = ((j - m->midx) * m->gap);
			new[i][j].z = m->pt[i][j].z;
			j++;
		}
		i++;
	}
	return (new);
}
