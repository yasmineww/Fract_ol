/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:00:04 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/04 19:31:37 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# define HEIGHT 800
# define WIDTH 800
# define MAX_ITER 100

typedef struct	values
{
	void	*init;
	void	*win;
	double	zoom;
	int		temp;
	double	x_min;
	double	y_min;
	double	x_max;
	double	y_max;
	double	c_x;
	double	c_y;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	all_vals;

typedef struct complex
{
	double	x;
	double	y;
}	n_complex;

// typedef struct val
// {
// 	t_number	str;
// 	t_number	end;
// }	values;

void	initialize_mlx(all_vals *ptr);
//mandelbrot
void	my_mandelbrot(all_vals *ptr);
n_complex	mapping_px(n_complex *comp, int x, int y, all_vals *ptr);
void	my_math(n_complex *comp, all_vals *ptr, int x, int y);
void	color_pixel(all_vals *ptr, int x, int y, int i);
void	my_pixel_put(all_vals *ptr, int x, int y, int color);
//utils
int	ft_strcmp(char *s1, char *s2);
//julia
void	my_julia(all_vals *ptr);
void	my_math_julia(n_complex *comp, all_vals *ptr, int x, int y);
/*void color_pixel_julia(t_data *img, int x, int y, int i);*/
//burning ship
void	my_burning_ship(all_vals *ptr);
void	my_burning_math(n_complex *comp, all_vals *ptr, int x, int y);
void	color_pixel_ship(all_vals *ptr, int x, int y, int i);
//hooks
int	mouse_hook(int mousecode, int x, int y, all_vals *fractal);
int	buttons(int keycode, all_vals *ptr);
int	esc(all_vals *ptr);
int	zoom(int button, int x, int y, all_vals *fract);
int	move_julia(int x, int y, all_vals *fractal);

#endif
