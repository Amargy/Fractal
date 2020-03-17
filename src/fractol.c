#include "fractol.h"

void	ptr_to_func(t_frak *f)
{
	if (f->type == 2)
	{
		f->funk = julia;
		f->numba.real = -0.70176;
		f->numba.fict = -0.3842;
	}
	else
	{
		f->type == 1 ? f->funk = mandelbrot : 0;
		f->type == 3 ? f->funk = ship : 0;
	}
}

int		preparation(t_frak *f)
{
	if (!(f->img.mlx = mlx_init()))
		ft_error("Mlx init error");
	if (!(f->img.win = mlx_new_window(f->img.mlx, WIDTH, HEIGHT, TITLE)))
		ft_error("Window init error");
	if (!(f->img.imag = mlx_new_image(f->img.mlx, WIDTH, HEIGHT)))
		ft_error("Image init error");
	if (!(f->img.data = mlx_get_data_addr(f->img.imag, &f->img.bpp,
		&f->img.lin_siz, &f->img.endi)))
		ft_error("Image address init error");
	f->img.bpp /= 8;
	f->img.kala = (t_color){.r = 0, .g = 0, .b = 0};
	f->jules = 0;
	f->min.x = -2.0f;
	f->min.y = -2.0f;
	f->max.x = 2.0f;
	f->max.y = 2.0f;
	f->move = (t_2dcoord){.x = 0, .y = 0};
	f->zoom = 1.0f;
	f->infinite = 99;
	ptr_to_func(f);
	return (1);
}

int		main(int argc, char **argv)
{
	t_frak	*f;

	if (argc == 2 && (argv[1][0] > 48 && argv[1][0] < 52 && argv[1][1] == '\0'))
	{
		if (!(f = malloc(sizeof(t_frak))))
			ft_error("Malloc is failed");
		f->type = (argv[1][0] - 48);
		if (!(preparation(f)))
		{
			del_img(f);
			ft_error("Preparation is failed");
		}
		instruction(f);
		fractal_processing(f);
	}
	else
		usage();
	return (0);
}
