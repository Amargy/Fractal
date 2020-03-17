#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"
# define WIDTH 				1280
# define HEIGHT				888
# define MOTION				6
# define MOVE_MASK			(1L << 6)
# define TITLE				"lets drop in to it"
# define W					13
# define S					1
# define ESC				53
# define UP					126
# define DOWN				125
# define LEFT				123
# define RIGHT				124
# define LSHIFT				257
# define SPACE				49
# define K1					18
# define K2					19
# define K3					20
# define K4					21
# define MOUSE_L			1
# define MOUSE_R			2
# define MOUSE_WHEEL_UP		4
# define MOUSE_WHEEL_DOWN	5

typedef	struct		s_map
{
	double			in_min;
	double			in_max;
	double			out_min;
	double			out_max;
}					t_map;

typedef	struct		s_cmplx
{
	double			real;
	double			fict;
}					t_cmplx;

typedef	struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef	struct		s_image
{
	void			*mlx;
	void			*win;
	int				*imag;
	char			*data;
	int				bpp;
	int				lin_siz;
	int				endi;
	t_color			kala;
}					t_image;

typedef	struct		s_2dcoord
{
	double			x;
	double			y;
}					t_2dcoord;

typedef struct		s_frak
{
	int				type;
	t_image			img;
	t_cmplx			numba;
	double			zoom;
	t_2dcoord		min;
	t_2dcoord		max;
	t_2dcoord		cent;
	t_2dcoord		move;
	unsigned int	iter;
	int				color_mode;
	int				jules;
	unsigned int	infinite;
	int				(*funk)(struct s_frak *f, int x, int y);
}					t_frak;

int					mouse_not_julia(int keycode, int x, int y, t_frak *f);
int					mouse_zoom_out(int x, int y, t_frak *f);
void				instruction(t_frak *f);
int					mouse_zoom_in(int x, int y, t_frak *f);
int					mouse_julia(int x, int y, t_frak *f);
int					hit_z_button(int keycode, t_frak *f);
int					move_button(int keycode, t_frak *f);
void				color_wat(int keycode, t_frak *f);
void				fractal_processing(t_frak *f);
void				process_pixel(t_frak *f);
void				put_pixel_to_img(t_frak *f, int x, int y);
void				pixel_color(t_frak *f, unsigned int depf);
void				need_more_colors(t_frak *f, int depf);
int					preparation(t_frak *f);
int					init_frak(t_frak *f);
void				ptr_to_func(t_frak *f);
int					calc_dourabbit(t_frak *f, int x, int y);
int					calc_siercarpet(t_frak *f, int x, int y);
int					ship(t_frak *f, int x, int y);
int					julia(t_frak *f, int x, int y);
int					mandelbrot(t_frak *f, int x, int y);
double				get_komplex_coord(double x, t_map p);
t_map				kapta_mark(double a, double b, double c, double d);
void				del_img(t_frak *f);
int					ft_error(char *s);
void				usage(void);
int					exit_press(void);

#endif
