/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:38:40 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/09 16:16:00 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	error_usage(void)
{
	ft_putendl("./fdf <FILE.fdf> -w [width] -h [height]\n");
	ft_putendl("-w specified the width");
	ft_putendl("-h specified the height");
	ft_putendl("Both width and height has to be greater than 500");
	exit(0);
}

void	window_prepare(int ac, char **av, t_env *m)
{
	int		i;

	if (ac < 2 || ac > 6)
		error_usage();
	m->file_name = ft_strjoin(ft_strdup(av[1]), " by KSONU");
	i = 1;
	m->win_x = 0;
	m->win_y = 0;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-w") && (i + 1) < ac)
		{
			m->win_x = ft_atoi(av[i + 1]);
			if (m->win_x < 500)
				error_usage();
		}
		else if (!ft_strcmp(av[i], "-h") && (i + 1) < ac)
		{
			m->win_y = ft_atoi(av[i + 1]);
			if (m->win_y < 500)
				error_usage();
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	t_env	m;
	int		fd;

	ft_bzero(&m, sizeof(t_env));
	window_prepare(ac, av, &m);
	fd = open(av[1], O_RDONLY);
	read_max(fd, &m);
	close(fd);
	fd = open(av[1], O_RDONLY);
	read_value(fd, &m);
	close(fd);
	m.mlx_ptr = mlx_init();
	m.win_ptr = mlx_new_window(m.mlx_ptr, m.win_x, m.win_y, m.file_name);
	init_struct(&m);
	mlx(&m);
}
