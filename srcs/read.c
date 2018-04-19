/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:50:11 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/18 20:15:11 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdio.h>

void		read_map_max(char **av, t_env *yap)
{
	int		fd;
	char	*line;
	int		y_count;
	int		x_count;
	char	**split;

	printf("1");
	line = NULL;
	y_count = 0;
	x_count = 0;
	yap->y_max = 0;
	yap->x_max = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		y_count++;
		split = ft_strsplit(line, ' ');
		while (*split[x_count])
			x_count++;
		ft_strdel(&line);
		ft_splitdel(split);
	}
	yap->y_max = y_count;
	yap->x_max = x_count;
}

void		read_value(char **av, t_env *yap)
{
	int		fd;
	char	*line;
	char	**split;
	int		i;

	printf("2");
	i = 0;
	line = NULL;
	read_map_max(&av[1], yap);
	fd = open(av[1], O_RDONLY);
	//yap->pt = (t_point)malloc(sizeof(t_point) * ((yap->y_max) * (yap->x_max)));
	yap->pt.y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		printf("3");
		split = ft_strsplit(line, ' ');
		while (split[i] != NULL)
		{
			printf("4");
			yap->pt.x = 0;
			yap->pt.z = ft_atoi(split[i]);
			i++;
			yap->pt.x++;
		}
		yap->pt.y++;
		ft_strdel(&line);
		ft_splitdel(split);
	}
}
