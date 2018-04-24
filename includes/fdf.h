#ifndef FDF_H
# define FDF_H
# define WIN_X 1280
# define WIN_Y 760
# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include <math.h>
# include <fcntl.h>

typedef struct		s_point
{
	float			x;
	float			y;
	int				z;
}					t_point;

typedef struct		s_env
{
	t_point			**pt;
	t_point			**peter;
	void			*mlx_ptr;
	void			*win_ptr;
	int				x_max;
	int				y_max;
	int				gap;
	int				midx;
	int				midy;
}					t_env;

int			read_max(int fd, t_env *m);
void		read_value(int fd, t_env *m);

void		mlx(t_env *m);
int			key_escape(int key);

void		ft_horizon(t_env *m);

void		ft_vertic(t_env *m);

#endif
