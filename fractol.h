#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include "../libft/libft.h"

typedef	struct		s_image
{
	void			*mlx;
	void			*win;
	int				*imag;
	char			*data;
	int				bpp;
	int				lin_siz;
	int				endi;
	t_color			c;
}					t_image;

typedef struct		s_fraktol
{
    int a;
}					t_fraktol;

#endif
