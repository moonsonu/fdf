/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:38:40 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/24 16:03:40 by ksonu            ###   ########.fr       */
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
		mlx(&m);
	}
}
