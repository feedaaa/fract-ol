/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:53:18 by ffidha            #+#    #+#             */
/*   Updated: 2024/05/27 17:54:36 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		death(char *reason)
{
	ft_putendl_fd(reason, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int		escape(char *reason)
{
	ft_putendl_fd(reason, STDERR_FILENO);
	exit(EXIT_SUCCESS);
}

int		main (int ac, char **av)
{
	t_fractal		fractal;

	if ((ac == 2 && ft_strncmp(av[1], "mandelbrot", 10))
			|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_real = atof(av[2]);
			fractal.julia_i = atof(av[3]);
		}
		fract_init(&fractal);
		fract_render(&fractal);
		mlx_loop(fractal.mlx);
	}
	death("Usage: ./fractol [mandelbrot/julia]");
}
