/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:00:04 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/01 18:51:59 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# define HEIGHT 800
# define WIDTH 800
# define MAX_ITER 100

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct complex
{
	double	x;
	double	y;
}	n_complex;

typedef struct gen_mlx
{
	void	*init;
	void	*win;
}	gen_mlx;

typedef struct hooks
{
	void	*mlx;
	void	*win;
}	v_hooks;

void	initialize_mlx(gen_mlx *ptr, t_data *img);
void	my_mandelbrot(t_data *img, gen_mlx *ptr);
n_complex	mapping_px(n_complex *comp, int x, int y);
void	my_math(n_complex *comp, t_data *img, int x, int y);
void	color_pixel(t_data *img, int x, int y, int i);
void	my_pixel_put(t_data *img, int x, int y, int color);

#endif
