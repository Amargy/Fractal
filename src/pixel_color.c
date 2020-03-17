#include "fractol.h"

void	need_more_colors(t_frak *f, int depf)
{
	if (f->color_mode == 2)
	{
		f->img.kala.r = ((int)sqrt(depf) * 30) % 255;
		f->img.kala.g = ((int)sqrt(depf) * 80) % 255;
		f->img.kala.b = (depf * 40) % 255;
	}
	else if (f->color_mode == 3)
	{
		f->img.kala.r = (depf * 5) % 255;
		f->img.kala.g = (depf * 5) % 255;
		f->img.kala.b = (depf * 5) % 255;
	}
}

void	pixel_color(t_frak *f, unsigned int depf)
{
	if (f->color_mode == 0)
	{
		if (depf == f->infinite)
		{
			f->img.kala.r = 0;
			f->img.kala.g = 0;
			f->img.kala.b = 0;
		}
		else
		{
			f->img.kala.r = (depf * 3) % 255;
			f->img.kala.g = (depf * 7) % 255;
			f->img.kala.b = (depf * 4) % 255;
		}
	}
	else if (f->color_mode == 1)
	{
		f->img.kala.r = (depf * 7) % 255;
		f->img.kala.g = (depf * 2) % 70;
		f->img.kala.b = (depf * 3) % 4;
	}
	else
		need_more_colors(f, depf);
}

void	color_wat(int keycode, t_frak *f)
{
	if (keycode == K_1)
		f->color_mode = 0;
	if (keycode == K_2)
		f->color_mode = 1;
	if (keycode == K_3)
		f->color_mode = 2;
	if (keycode == K_4)
		f->color_mode = 3;
	if ((keycode == K_1) || (keycode == K_2) ||
		(keycode == K_3) || (keycode == K_4))
		fractal_processing(f);
}
