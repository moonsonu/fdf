/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:38:40 by ksonu             #+#    #+#             */
/*   Updated: 2018/05/12 18:44:32 by ksonu            ###   ########.fr       */
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

void	error_invalidmap(void)
{
	ft_putendl("Invalid input file\n");
	exit(0);
}

void	window_prepare(int ac, char **av, t_env *m)
{
	int		i;

	if (ac < 2 || ac > 6)
		error_usage();
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
	m->win_x == 0 ? m->win_x = 1280 : 0;
	m->win_y == 0 ? m->win_y = 760 : 0;
}

void		validation(char *line)
{
	int		i;

	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			error_invalidmap();
		else if (line[i] < ' ' && line[i] != '\n')
			error_invalidmap();
		else if (line[i] > ' ' && line[i] < ',')
			error_invalidmap();
		else if (line[i] > '-' && line[i] < '0')
			error_invalidmap();
		else if (line[i] > '9' && line[i] < 'A')
			error_invalidmap();
		else if (line[i] > 'F' && line[i] < 'a')
			error_invalidmap();
		else if (line[i] > 'f' && line[i] != 'x')
			error_invalidmap();
	}
}

int		main(int ac, char **av)
{
	t_env	m;
	int		fd;

	ft_bzero(&m, sizeof(t_env));
	m.file_name = ft_strjoin(av[1], " by KSONU");
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
