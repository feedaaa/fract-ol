/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:37:24 by ffidha            #+#    #+#             */
/*   Updated: 2024/05/27 17:53:40 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// look this up on mlx video oceano
static void		put_pixel(int x, int y, t_img *img, int color)
{
	int		offset;
	
	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{	
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->real = fractal->julia_real;
		c->i = fractal->julia_i;
	}
	else
	{
		c->real = z->real;
		c->i = z->i;
	}
}

static void		handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex		z;
	t_complex		c;
	int				i;
	int				color;

	i = 0;
	z.real = 0.0;
	z.i = 0.0;

	c.real = (scale(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	c.i = (scale(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;

	while (i < fractal->iterations)
	{
		z = sum(square(z), c);
		if ((z.real * z.real) + (z.i * z.i) > fractal->hypotenuse)
		{
			color = scale(i, BLACK, WHITE, fractal->iterations);
			put_pixel(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	put_pixel(x, y, &fractal->img, LIME_SHOCK);	
}
void		fract_render(t_fractal *fractal)
{
	int		x;
	int		y;
	
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,
			fractal->img.img_ptr, 0, 0);
}