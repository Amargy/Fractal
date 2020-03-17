#include "fractol.h"

t_map	kapta_mark(double a, double b, double c, double d)
{
	t_map	p;

	p.in_min = a;
	p.in_max = b;
	p.out_min = c;
	p.out_max = d;
	return (p);
}

double	get_komplex_coord(double x, t_map p)
{
	double ret;
	
	ret = p.out_min + (p.out_max - p.out_min) * ((x - p.in_min)
		/ (p.in_max - p.in_min));
	return (ret);
}

void	put_pixel_to_img(t_frak *f, int x, int y)
{
	if ((x >= 0 || x <= WIDTH) && (y >= 0 || y <= HEIGHT))
	{
		f->img.data[(x * 4) + (y * WIDTH * 4) + 2] = f->img.kala.r;
		f->img.data[(x * 4) + (y * WIDTH * 4) + 1] = f->img.kala.g;
		f->img.data[(x * 4) + (y * WIDTH * 4)] = f->img.kala.b;
	}
}

void	process_pixel(t_frak *f)
{
	int				x;
	int				y;
	unsigned int	tmp_color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			tmp_color = f->funk(f, x, y);
			pixel_color(f, tmp_color);
			put_pixel_to_img(f, x, y);
			x++;
		}
		y++;
	}
}

void	fractal_processing(t_frak *f)
{
	mlx_clear_window(f->img.mlx, f->img.win);
	process_pixel(f);
	mlx_put_image_to_window(f->img.mlx, f->img.win, f->img.imag, 0, 0);
	mlx_hook(f->img.win, 2, 5, hit_z_button, f);
	mlx_hook(f->img.win, 17, 1L << 17, exit_press, NULL);
	mlx_mouse_hook(f->img.win, mouse_not_julia, f);
	mlx_hook(f->img.win, MOTION, MOVE_MASK, mouse_julia, f);
	mlx_loop(f->img.mlx);
}
