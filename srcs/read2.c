/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksonu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:21:29 by ksonu             #+#    #+#             */
/*   Updated: 2018/04/18 19:10:57 by ksonu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
typedef struct		s_max
{
	int		x_max;
	int		y_max;
}					t_max;

int		ft_wdcount(char *str, char c)
{
	int		result;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] == c)
			word = 0;
		else if (str[i] != c && word == 0)
		{
			word = 1;
			result++;
		}
		i++
	}
	return (result);
}

char		get_max(int fd)
{
	char	**split;
	char	*line;
	int		x_count;
	int		y_count;
	t_max	*max;

	y_count = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		x_count = 0;
		while (!(split = ft_strsplit(&line, ' ')))
			x_count++;
		y_count++;
	}
	max.x_max = x_count;
	max.y_max = y_count;
	ft_strdel(line);
	ft_splitdel(split);
}

char		read_map(int fd)
{
	char	**split;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	split = NULL;
	t_point.point_x = 0;
	t_point.point_y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(&line, ' ');
		while (split[i] != '\0')
		{
			t_point[p].alt = ft_atoi(split[i]);
			i++;
			t_point.point_x++;
		}
		p++;
		t_point.point_y++;
	}
	ft_strdel(line);
	ft_splitdel(split);
}

