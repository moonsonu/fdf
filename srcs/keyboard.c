/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 00:06:28 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/24 00:18:07 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		key_escape(int key)
{
	if (key == 53)
	{
		exit(0);
		return (0);
	}
}

int		key_rot(int key)
{
	//123left 125down 124right 126up
	if (key == 123)
}

int		key_zoom(int key)
{
	//27minus 24equal
	if (key == 27)

}

void	key_board(t_env *m)
{
	mlx_key_hook(m->win_ptr, key_escape, 0);
	mlx_key_hook(m->win_ptr, key_rot, 0);
	mlx_key_hook(m->win_ptr, key_zoom, 0);
}
