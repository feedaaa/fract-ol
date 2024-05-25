/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:38:34 by ffidha            #+#    #+#             */
/*   Updated: 2024/05/25 15:23:37 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// scales values [0-1080] into [-2 - 2]

double	scale(double unscaled_num, double new_min,
		double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0)
		/ (old_max - 0) + new_min);
}

t_complex	sum(t_complex z1, t_complex z2)

{
	t_complex	result;

	result.real = z1.real + z2.i;
	result.i = z1.i + z2.i;
	return (result);
}

t_complex	square(t_complex z)
{
	t_complex	result;

	result.real = (z.real * z.real) - (z.i * z.i);
	result.i = 2 * z.real * z.i;
	return (result); 
}

