#include "fractol.h"

int		move_button(int keycode, t_frak *f)
{
	if (keycode == UP)
	{
		f->min.y += 0.1 * f->zoom;
		f->max.y += 0.1 * f->zoom;
		fractal_processing(f);
	}
	if (keycode == DOWN)
	{
		f->min.y -= 0.1 * f->zoom;
		f->max.y -= 0.1 * f->zoom;
		fractal_processing(f);
	}
	if (keycode == LEFT)
	{
		f->min.x += 0.1 * f->zoom;
		f->max.x += 0.1 * f->zoom;
		fractal_processing(f);
	}
	if (keycode == RIGHT)
	{
		f->min.x -= 0.1 * f->zoom;
		f->max.x -= 0.1 * f->zoom;
		fractal_processing(f);
	}
	return (-1);
}

int		hit_z_button(int keycode, t_frak *f)
{
	if (keycode == ESC)
		exit(1);
	move_button(keycode, f);
	if (keycode == LSHIFT)
		f->jules = (f->jules + 1) % 2;
	if (keycode == W)
	{
		f->infinite += 9;
		fractal_processing(f);
	}
	if (keycode == S)
	{
		f->infinite -= 9;
		fractal_processing(f);
	}
	if (keycode == SPACE)
	{
		preparation(f);
		fractal_processing(f);
	}
	color_wat(keycode, f);
	return (-1);
}
