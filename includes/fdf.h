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
	t_point 		**pt;
	void			*mlx_ptr;
	void			*win_ptr;
	int				x_max;
	int				y_max;
	int				window_x;
	int				window_y;
	int				grid_x;
	int				grid_y;
}					t_env;

void		read_max(int fd, t_env *m);
void		read_value(int fd, t_env *m);
#endif
