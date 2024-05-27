/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:09:11 by ffidha            #+#    #+#             */
/*   Updated: 2024/05/27 17:55:54 by ffidha           ###   ########.fr       */
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
#define WIDTH 800
#define HEIGHT 800

// colors
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red



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
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_i;
	double		julia_real;
}			t_fractal;

//Error functions
int				death(char *reason);
int				escape(char *reason);

//inits
void			fract_init(t_fractal *fractal);
void			data_init(t_fractal *fractal);
void			fract_render(t_fractal *fractal);

// math functions
double			scale(double unscaled_num, double new_min,
		double new_max, double old_max);
t_complex		sum(t_complex z1, t_complex z2);
t_complex		square(t_complex z);

// utils
void			ft_putendl_fd(char *s, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
double			atof(char *s);

// movements/events
int				key_handler(int keycode, t_fractal *fractal);
int				close_handler(t_fractal *fractal);
int				mouse_handler(int button, int x, int y, t_fractal *fractal);

#endif