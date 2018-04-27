/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:38:40 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/26 17:12:08 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_env	m;
	int		fd;

	m = *(t_env*)ft_memalloc(sizeof(t_env));
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		read_max(fd, &m);
		fd = open(av[1], O_RDONLY);
		read_value(fd, &m);
		m.mlx_ptr = mlx_init();
		m.win_ptr = mlx_new_window(m.mlx_ptr, WIN_X, WIN_Y, "MOON");
		init_struct(&m);
		mlx(&m);
	}
}
