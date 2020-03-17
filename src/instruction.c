#include "fractol.h"

int		exit_press(void)
{
	exit(1);
	return (0);
}

void	del_img(t_frak *f)
{
	if (f->img.win)
		mlx_destroy_window(f->img.mlx, f->img.win);
	if (f->img.imag)
		mlx_destroy_image(f->img.mlx, f->img.imag);
	ft_memdel((void **)&f->img.mlx);
	free(f);
}

int		ft_error(char *s)
{
	ft_putendl(s);
	exit(-1);
}

void	usage(void)
{
	ft_putendl("Usage: ./fractol Number as argument");
	ft_putendl("1 - Mandelbrot, 2 - Julia, 3 - Burning Ship");
	ft_putendl("4 - Sierpinski Carpet, 5 - Douady Rabbit");
	exit(-1);
}

void	instruction(t_frak *f)
{
	if (f->funk == julia)
	{
		ft_putendl("JULIA FRAKTAL CONTROLS:");
		ft_putendl("LEFT - ARROW LEFT, RIGHT - ARROW RIGHT");
		ft_putendl("UP - ARROW UP, DOWN - ARROW DOWN");
		ft_putendl("Zoom In - Left Mouse Button/Mouse Wheel Up");
		ft_putendl("Zoom Out - Right Mouse Button/Mouse Wheel Down");
		ft_putendl("CHANGE COLOR - 1, 2, 3");
		ft_putendl("BLACK&WHITE MODE - 4");
		ft_putendl("MOVING MODE ENABLE - LEFT SHIFT");
		ft_putendl("MOVING WITH MOUSE");
		ft_putendl("RESET - SPACE");
	}
	else
	{
		ft_putendl("FRAKTAL CONTROLS:");
		ft_putendl("LEFT - ARROW LEFT, RIGHT - ARROW RIGHT");
		ft_putendl("UP - ARROW UP, DOWN - ARROW DOWN");
		ft_putendl("Zoom In - Left Mouse Button/Mouse Wheel Up");
		ft_putendl("Zoom Out - Right Mouse Button/Mouse Wheel Down");
		ft_putendl("CHANGE COLOR - 1, 2, 3");
		ft_putendl("BLACK&WHITE MODE - 4");
		ft_putendl("RESET - SPACE");
	}
}
