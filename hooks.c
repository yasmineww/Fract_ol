/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:25:55 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/04 22:48:57 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	buttons(int keycode, all_vals *ptr)
{
	if (keycode == 53)
		esc(ptr);
	return (0);
}

int	esc(all_vals *ptr)
{
	mlx_destroy_image(ptr->init, ptr->img);
	mlx_destroy_window(ptr->init, ptr->win);
	exit(0);
	return (0);
}

int	zoom(int button, int x, int y, all_vals *fract)
{
	double	mousex;
	double	mousey;
	double	zoom;

	if (button == 5 || button == 4)
	{
		mousex = fract->x_min + ((double)x / WIDTH)
			* (fract->x_max - fract->x_min);
		mousey = fract->y_min + ((double)y / HEIGHT)
			* (fract->y_max - fract->y_min);
		if (button == 5)
			zoom = 0.8;
		else
			zoom = 1.2;
		fract->zoom *= zoom;
		fract->x_min = mousex + zoom * (fract->x_min - mousex);
		fract->x_max = mousex + zoom * (fract->x_max - mousex);
		fract->y_min = mousey + zoom * (fract->y_min - mousey);
		fract->y_max = mousey + zoom * (fract->y_max - mousey);
		if (fract->temp == 1)
			my_mandelbrot(fract);
		else if (fract->temp == 2)
			my_julia(fract);
		else if (fract->temp == 3)
			my_burning_ship(fract);
	}
	else if (button == 1)
	{
		
	}
}

int	move_julia(int x, int y, all_vals *fractal)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		fractal->c_x = (double)x / WIDTH;
		fractal->c_y = (double)y / HEIGHT;
		my_julia(fractal);
	}
	return (0);
}

// int	mouse_hook(int button, int x, int y, all_vals *ptr)
// {
// 	if ()
// }
