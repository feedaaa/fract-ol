/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:09:11 by ffidha            #+#    #+#             */
/*   Updated: 2024/05/25 20:29:25 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h> //write
#include <stdlib.h> //allocation and free
#include <stdio.h> //debugging
#include "mlx/mlx.h" //minilibx
#include <math.h> //math functions

// size of the window
#define WIDTH 1920
#define HEIGHT 1080

// colors
#define BLACK  0x000000
#define WHITE  0xFFFFFF
#define RED     0xFF0000
#define GREEN   0x00FF00
#define YELLOW  0xFFFF00
#define BLUE    0x0000FF
#define MAGENTA 0xFF00FF
#define CYAN    0x00FFFF
#define LIGHT_RED   0xFFA500
#define LIGHT_YELLOW  0xFFFFE0
#define LIGHT_BLUE  0xADD8E6
#define LIGHT_MAGENTA 0xFFE4E1
#define LIGHT_CYAN  0xAFEEEE


//complex numbers struct
typedef struct  s_complex
{
	// x-axis
	double  real;
	// y-axis
	double  i;
}               t_complex;

//image struct
typedef struct s_img
{
	void		*img_ptr; //ptr to image
	char		*pixel_ptr; //PTR to first pixel of image
	int			bits_per_pixel; //bits per pixel
	int			line_length; //line length
	int			endian; //endian
}               t_img;

// Fractal struct
typedef struct	s_fractal 
{
	char		*name;
	// MLX-> init and new window
	void		*mlx;
	void		*mlx_win;

	// image
	t_img		img;

	// hooks
	double		hypotenuse;
	int			iterations; // effects the image quality and speed
}			t_fractal;

//Error functions
int				death(char *reason);
int				escape(char *reason);

//inits
void			fract_init(t_fractal *fractal);
void			fract_render(t_fractal *fractal);
void			data_init(t_fractal *fractal);

// math functions
double			scale(double unscaled_num, double new_min,
		double new_max, double old_max);
t_complex		sum(t_complex z1, t_complex z2);
t_complex		square(t_complex z);

// utils
void	ft_putendl_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif