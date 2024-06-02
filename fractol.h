/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:09:11 by ffidha            #+#    #+#             */
/*   Updated: 2024/05/28 19:34:52 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <ctype.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000 // RGB(0, 0, 0)
# define WHITE 0xFFFFFF // RGB(255, 255, 255)
# define RED 0xFF0000   // RGB(255, 0, 0)
# define GREEN 0x00FF00 // RGB(0, 255, 0)
# define BLUE 0x0000FF  // RGB(0, 0, 255)

# define MAGENTA_BURST 0xFF00FF
# define LIME_SHOCK 0xCCFF00
# define NEON_ORANGE 0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM 0x33CCCC
# define HOT_PINK 0xFF66B2
# define ELECTRIC_BLUE 0x0066FF
# define LAVA_RED 0xFF3300

typedef struct s_complex
{
	double		real;
	double		i;
}			t_complex;

typedef struct s_img
{
	void		*img_ptr;
	char		*pixel_ptr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}			t_img;

typedef struct s_fractal
{
	char		*name;
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	double		hypotenuse;
	int			iterations;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_i;
	double		julia_real;
}			t_fractal;

int				death(char *reason);
int				escape(char *reason);
void			fract_init(t_fractal *fractal);
void			data_init(t_fractal *fractal);
void			fract_render(t_fractal *fractal);
double			scale(double unscaled_num, double new_min, double new_max,
					double old_max);
t_complex		sum(t_complex z1, t_complex z2);
t_complex		square(t_complex z);
void			ft_putendl_fd(char *s, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
double			atobbl(char *s);
int				julia_param_check(const char *param);
int				key_handler(int keycode, t_fractal *fractal);
int				close_handler(t_fractal *fractal);
int				mouse_handler(int button, int x, int y, t_fractal *fractal);
int				julia_track(int x, int y, t_fractal *fractal);
#endif