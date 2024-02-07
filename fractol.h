/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:00:04 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/06 20:01:38 by ymakhlou         ###   ########.fr       */
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
# define MAX_ITER 70

typedef struct	values
{
	void	*init;
	void	*win;
	double	zoom;
	int		temp;
	int		tr;
	int		iter;
	int		R;
	int		G;
	int		B;
	double	x_min;
	double	y_min;
	double	x_max;
	double	y_max;
	double	c_x;
	double	c_y;
	double	move_x;
	double	move_y;
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

void	initialize_mlx(all_vals *ptr);
void	hook_functions(all_vals *ptr);
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
//burning ship
void	my_burning_ship(all_vals *ptr);
void	my_burning_math(n_complex *comp, all_vals *ptr, int x, int y);
void	color_pixel_ship(all_vals *ptr, int x, int y, int i);
//hooks
int	buttons(int keycode, all_vals *ptr);
int	esc(all_vals *ptr);
int	zoom(int button, int x, int y, all_vals *ptr);
int	move_julia(int x, int y, all_vals *ptr);

#endif