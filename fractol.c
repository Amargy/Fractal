int		preparation(t_fractol *f)
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
	return (1);
}

int		ft_error(char *s)
{
	ft_putendl(s);
	exit(1);
}

int		usage()
{
	ft_putendl("Usage: ./fractol Number as argument");
	ft_putendl("1 - Mandelbrot, 2 - Julia, 3 - Burning Ship");
	exit (-1);
}

int		check_arg(char *argu)
{
	if (argu[0] > 48 && argu[0] < 54 && argu[1] == '\0')
		return (argu[0] - 48);
	else
		return (0);
}

int     main(int argc, char **argv)
{
	t_fractol *f;

	if (argc == 2 && f->type = check_arg(argv[1]))
	{
		if (!(f = malloc(sizeof(t_fraktol))))
			ft_error("Malloc is failed.);
		if (!(preparation))
		{
			
		}
	}
	else
		usage();
	return (0);
}