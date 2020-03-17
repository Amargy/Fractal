#include "fractol.h"

int		mouse_zoom_out(int x, int y, t_frak *f)
{
	double zum_ratio;
	double movex;
	double movey;

	if (f->zoom <= 2)
	{
		movex = (double)x * (double)((f->max.x - f->min.x)
			/ (double)WIDTH) + f->min.x;
		movey = (double)y * (double)((f->max.y - f->min.y)
			/ (double)HEIGHT) + f->min.y;
		zum_ratio = 1.1f;
		f->zoom *= zum_ratio;
		f->max.x = f->max.x * zum_ratio + movex * (1 - zum_ratio);
		f->min.x = f->min.x * zum_ratio + movex * (1 - zum_ratio);
		f->max.y = f->max.y * zum_ratio + movey * (1 - zum_ratio);
		f->min.y = f->min.y * zum_ratio + movey * (1 - zum_ratio);
		fractal_processing(f);
	}
	return (0);
}

int		mouse_not_julia(int keycode, int x, int y, t_frak *f)
{
	if (keycode == MOUSE_L || keycode == MOUSE_WHEEL_UP)
		mouse_zoom_in(x, y, f);
	else if (keycode == MOUSE_R || keycode == MOUSE_WHEEL_DOWN)
		mouse_zoom_out(x, y, f);
	return (0);
}

int		mouse_julia(int x, int y, t_frak *f)
{
	double tmpx;
	double tmpy;

	if (f->jules == 1)
	{
		tmpx = kapta(x, kapta_mark(0, WIDTH, -1, 1));
		tmpy = kapta(y, kapta_mark(0, HEIGHT, -1, 1));
		f->numba.real = tmpx;
		f->numba.fict = tmpy;
		fractal_processing(f);
	}
	return (0);
}

int		mouse_zoom_in(int x, int y, t_frak *f)
{
	double	zum_ratio;
	double	movex;
	double	movey;

	movex = (double)x * (double)((f->max.x - f->min.x)
		/ (double)WIDTH) + (double)f->min.x;
	movey = (double)y * (double)((f->max.y - f->min.y)
		/ (double)HEIGHT) + (double)f->min.y;
	zum_ratio = 0.9f;
	f->zoom *= zum_ratio;
	f->max.x = f->max.x * zum_ratio + movex * (1 - zum_ratio);
	f->min.x = f->min.x * zum_ratio + movex * (1 - zum_ratio);
	f->max.y = f->max.y * zum_ratio + movey * (1 - zum_ratio);
	f->min.y = f->min.y * zum_ratio + movey * (1 - zum_ratio);
	fractal_processing(f);
	return (0);
}
