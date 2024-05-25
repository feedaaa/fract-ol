/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:55:08 by ffidha            #+#    #+#             */
/*   Updated: 2024/05/25 18:35:16 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_fractal *fractal)
{
	// 2^2
	fractal->hypotenuse = 4;
	fractal->iterations = 42;
}

void	fract_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		death("allocation probs");
	fractal->mlx_win = mlx_new_window(fractal->mlx, WIDTH,
			HEIGHT, fractal->name);
	if (fractal->mlx_win == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		free(fractal->mlx);
		death("allocation probs");
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (fractal->img.img_ptr)
	{
		mlx_destroy_image(fractal->mlx, fractal->img. img_ptr);
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		free(fractal->mlx);
		death("allocation probs");
	}
	fractal->img. pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bits_per_pixel,
		&fractal->img.line_length, &fractal->img.endian);
	//events_init(fractal);
	data_init(fractal);
}
