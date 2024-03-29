/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:00:04 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/10 16:22:04 by ymakhlou         ###   ########.fr       */
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

typedef struct values
{
	void	*init;
	void	*win;
	double	zoom;
	int		temp;
	int		tr;
	int		iter;
	int		color;
	int		max;
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
}	t_vals;

typedef struct complex
{
	double	x;
	double	y;
}	t_complex;

t_complex	mapping_px(t_complex *comp, int x, int y, t_vals *ptr);
void		initialize_mlx(t_vals *ptr);
void		my_mandelbrot(t_vals *ptr);
void		my_math(t_complex *comp, t_vals *ptr, int x, int y);
void		my_pixel_put(t_vals *ptr, int x, int y, int color);
double		parsing(char *av);
int			valid_param(char *av);
double		handle_param(char *av, int *res1);
void		check_args(char *av, t_vals *ptr);
void		my_julia(t_vals *ptr);
void		my_math_julia(t_complex *comp, t_vals *ptr, int x, int y);
void		my_burning_ship(t_vals *ptr);
void		my_burning_math(t_complex *comp, t_vals *ptr, int x, int y);
int			buttons(int keycode, t_vals *ptr);
int			esc(t_vals *ptr);
int			zoom(int button, int x, int y, t_vals *ptr);
int			move_julia(int x, int y, t_vals *ptr);
void		zoom_calc(t_vals *ptr, int x, int y, int button);

#endif