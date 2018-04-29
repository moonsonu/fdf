#ifndef FDF_H
# define FDF_H
# define WIN_X 1280
# define WIN_Y 760
# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_point
{
	float			x;
	float			y;
	int				z;
	int				color;
}					t_point;

typedef struct		s_env
{
	t_point			**pt;
	t_point			**pt_new;
	t_point			**peter;
	void			*mlx_ptr;
	void			*win_ptr;
	int				x_max;
	int				y_max;
	int				gap;
	int				midx;
	int				midy;
	float			x_angle;
	float			y_angle;
	float			z_angle;
	int				z_gap;
	int				x_move;
	int				y_move;
	int				color;
}					t_env;

int			read_max(int fd, t_env *m);
void		read_value(int fd, t_env *m);
void		read_dup(t_env *m);

void		mlx(t_env *m);
void		mlx_message(t_env *m);

void		ft_horizon(t_env *m);
void		get_zxy(t_env *m);
void		ft_draw_x(t_env *m, int i, int j);
void		init_struct(t_env *m);

void		ft_vertic(t_env *m);
void		get_zyx(t_env *m);
void		ft_draw_y(t_env *m, int i, int j);

void		rotation_x(t_env *m);
void		rotation_y(t_env *m);
void		rotation_z(t_env *m);
void		ft_rotate(t_env *m);

int			keyfunction(int key, t_env *m);
void		key_zoom(int key, t_env *m);

int			mousefunction(int key, int x, int y, t_env *m);

void		key_color_1(t_env *m);
void		key_color_2(t_env *m);
void		key_color_3(t_env *m);
void		key_color_4(t_env *m);
#endif
