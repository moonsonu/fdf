/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:05:24 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/17 18:03:57 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		xi = 0;
	int		yi = 0;
	int		xf = 300;
	int		yf = 300;
	int		w = xf - xi;
	int		h = yf - yi;
	int		f = (2 * h) - w;
	int		f1 = 2 * h;
	int		f2 = 2 * (h - w);

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 300, 300, "moonyoning");
	while (xi <= xf)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, xi, yi, 0xFFFFFF);
		if (f < 0)
			f += f1;
		else
		{
			++yi;
			f += f2;
		}
		++xi;
	}
	mlx_loop(mlx_ptr);
}
