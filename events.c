/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:34:06 by ffidha            #+#    #+#             */
/*   Updated: 2024/05/27 17:39:13 by ffidha           ###   ########.fr       */
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
	else if (keycode == 126) // UP
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keycode == 125) // down
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if(keycode == 123) // left
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if(keycode == 124) // right
		fractal->shift_x += (0.5 * fractal->zoom);
	else if(keycode == 69) // zoom in
		fractal->iterations += 10;
	else if(keycode == 78) //zoom out 
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

