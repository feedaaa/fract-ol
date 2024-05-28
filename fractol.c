/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:53:18 by ffidha            #+#    #+#             */
/*   Updated: 2024/05/28 19:09:23 by ffidha           ###   ########.fr       */
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

int	julia_params(t_fractal *fractal, char **av)
{
	if (av[2] == NULL || av[3] == NULL)
		death("julia needs her params pls :)");
	if (!julia_param_check(av[2]) || !julia_param_check(av[3]))
		death("those params is a no no");
	fractal->julia_real = atobbl(av[2]);
	fractal->julia_i = atobbl(av[3]);
	if (fractal->julia_real < -2 || fractal->julia_real > 2
		|| fractal->julia_i < -2 || fractal->julia_i > 2)
		death("params should be between -2 and +2");
	return(1);
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
			if (!julia_params(&fractal, av))
			{
				death("julia erse tu?");
			}
			fractal.julia_real = atobbl(av[2]);
			fractal.julia_i = atobbl(av[3]);
		}
		fract_init(&fractal);
		fract_render(&fractal);
		mlx_loop(fractal.mlx);
	}
	death("Usage: ./fractol [mandelbrot/julia]");
}
