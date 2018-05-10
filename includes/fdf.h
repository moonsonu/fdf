#ifndef FDF_H
# define FDF_H
# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	float			x_tmp;
	float			y_tmp;
	float			z_tmp;
	int				color;
}					t_point;

typedef struct		s_env
{
	t_point			**pt;
	t_point			**pt_new;
	t_point			**peter;
	void			*mlx_ptr;
	void			*win_ptr;
	char			*file_name;
	int				win_x;
	int				win_y;
	int				x_max;
	int				y_max;
	int				z_max;
	int				z_min;
	float			gap;
	int				midx;
	int				midy;
	float			x_angle;
	float			y_angle;
	float			z_angle;
	float			zoom;
	float			zoom_x;
	float			zoom_y;
	float			window;
	float			z_gap;
	int				x_move;
	int				y_move;
	int				color;
	int				z_move;
}					t_env;

int			read_max(int fd, t_env *m);
void		read_value(int fd, t_env *m);
void		read_dup(t_env *m);

void		mlx(t_env *m);
void		mlx_message(t_env *m);
void		prepare_zscale(t_env *m, t_point pt);
void		init_struct(t_env *m);
void		midpoint(t_env *m);

void		ft_horizon(t_env *m);
void		get_zxy(t_env *m);
void		ft_draw_x(t_env *m, int i, int j);
void		init_struct(t_env *m);
void		prepare_pt(t_env *m);

void		ft_vertic(t_env *m);
void		get_zyx(t_env *m);
void		ft_draw_y(t_env *m, int i, int j);

void		rotation_x(t_env *m);
void		rotation_y(t_env *m);
void		rotation_z(t_env *m);
void		ft_rotate(t_env *m, int key);

int			keyfunction(int key, t_env *m);
void		key_zoom(int key, t_env *m);

//int			mousefunction(int key, int x, int y, t_env *m);

void		key_color_1_x(t_env *m);
void		key_color_1_y(t_env *m);
void		key_color_2_x(t_env *m);
void		key_color_2_y(t_env *m);
void		key_color_3_x(t_env *m);
void		key_color_3_y(t_env *m);
#endif
