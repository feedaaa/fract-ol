/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:34:06 by ffidha            #+#    #+#             */
/*   Updated: 2024/05/28 19:27:24 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
		close_handler(fractal);
	else if (keycode == 126)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keycode == 125)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keycode == 123)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keycode == 124)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keycode == 69)
		fractal->iterations += 10;
	else if (keycode == 78)
		fractal->iterations -= 10;
	fract_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 5)
		fractal->zoom *= 0.95;
	else if (button == 4)
		fractal->zoom *= 1.05;
	fract_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_real = (scale(x, -2, +2, WIDTH) * fractal->zoom)
			+ fractal->shift_x;
		fractal->julia_i = (scale(y, +2, -2, HEIGHT) * fractal->zoom)
			+ fractal->shift_y;
		fract_render(fractal);
	}
	return (0);
}
