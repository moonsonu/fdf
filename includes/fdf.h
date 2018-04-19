#ifndef FDF_H
# define FDF_H
# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include <math.h>
# include <fcntl.h>

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_env
{
	struct s_point 	pt;
	int				x_max;
	int				y_max;
	int				window_x;
	int				window_y;
	int				grid_x;
	int				grid_y;
}					t_env;

void		read_map_max(char **av, t_env *yap);
void		read_value(char **av, t_env *yap);
#endif
