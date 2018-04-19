/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:05:24 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/18 20:24:11 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;
	t_env	*yap = NULL;

	printf("aasd");
	if (ac != 2)
	{
		ft_putstr("usage : fdf input_file\n");
		return (1);
	}
	if ((fd = (open(av[1], O_RDONLY))) < 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	else
	{
		printf("1234");
		read_map_max(&av[1], yap);
		printf("5678");
		read_value(&av[1], yap);
		printf("ymax[%d]", yap->y_max);
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 300, 300, "moonyoning");
	mlx_loop(mlx_ptr);
	return (0);
}
