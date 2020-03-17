#include "fractol.h"

int		mandelbrot(t_frak *f, int x, int y)
{
	double	fx;
	double	fy;
	double	k_ril;
	double	k_fic;
	double	tmpx;

	f->iter = 0;
	fx = 0;
	fy = 0;
	k_ril = get_komplex_coord(x, kapta_mark(0, WIDTH, f->min.x, f->max.x));
	k_fic = get_komplex_coord(y, kapta_mark(0, HEIGHT, f->min.y, f->max.y));
	while (f->iter < f->infinite)
	{
		tmpx = (fx * fx - fy * fy) + k_ril;
		fy = 2 * fx * fy + k_fic;
		fx = tmpx;
		if ((fx * fx + fy * fy) > 4)
			break ;
		f->iter++;
	}
	return (f->iter);
}

int		julia(t_frak *f, int x, int y)
{
	double mx;
	double my;
	double tmpx;

	f->iter = 0;
	mx = get_komplex_coord(x, kapta_mark(0, WIDTH, f->min.x, f->max.x));
	my = get_komplex_coord(y, kapta_mark(0, HEIGHT, f->min.y, f->max.y));
	while (f->iter < f->infinite)
	{
		tmpx = (mx * mx - my * my) + f->numba.real;
		my = 2.0f * mx * my + f->numba.fict;
		mx = tmpx;
		if ((mx * mx + my * my) > 4.0f)
			break ;
		f->iter++;
	}
	return (f->iter);
}

int		ship(t_frak *f, int x, int y)
{
	double fx;
	double fy;
	double k_ril;
	double k_fic;
	double tmpx;

	f->iter = 0;
	fx = 0;
	fy = 0;
	k_ril = get_komplex_coord(x, kapta_mark(0, WIDTH, f->min.x, f->max.x));
	k_fic = get_komplex_coord(y, kapta_mark(0, HEIGHT, f->min.y, f->max.y));
	while (f->iter < f->infinite)
	{
		tmpx = (fx * fx - fy * fy) + k_ril;
		fy = fabs(2 * fx * fy + k_fic);
		fx = fabs(tmpx);
		if ((fx * fx + fy * fy) > 4)
			break ;
		f->iter++;
	}
	return (f->iter);
}
