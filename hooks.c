/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:25:55 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/10 01:25:47 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	buttons(int keycode, t_vals *ptr)
{
	if (keycode == 53)
		esc(ptr);
	else if (keycode == 49)
		ptr->color += (ptr->color << 4);
	else if (keycode == 0)
		ptr->move_x -= (0.5 * ptr->zoom);
	else if (keycode == 1)
		ptr->move_y += (0.5 * ptr->zoom);
	else if (keycode == 2)
		ptr->move_x += (0.5 * ptr->zoom);
	else if (keycode == 13)
		ptr->move_y -= (0.5 * ptr->zoom);
	mlx_clear_window(ptr->init, ptr->win);
	if (ptr->temp == 1)
		my_mandelbrot(ptr);
	else if (ptr->temp == 2)
		my_julia(ptr);
	else if (ptr->temp == 3)
		my_burning_ship(ptr);
	return (0);
}

int	esc(t_vals *ptr)
{
	mlx_destroy_image(ptr->init, ptr->img);
	mlx_destroy_window(ptr->init, ptr->win);
	exit(0);
	return (0);
}

void	zoom_calc(t_vals *ptr, int x, int y, int button)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom;

	mouse_x = (x * (ptr->x_max - ptr->x_min) / WIDTH) + ptr->x_min;
	mouse_y = (y * (ptr->y_max - ptr->y_min) / HEIGHT) + ptr->y_min;
	if (button == 5)
	{
		ptr->max += 3;
		zoom = 0.8;
	}
	else
	{
		ptr->max -= 2;
		zoom = 1.2;
	}
	ptr->zoom *= zoom;
	ptr->x_min = mouse_x + zoom * (ptr->x_min - mouse_x);
	ptr->x_max = mouse_x + zoom * (ptr->x_max - mouse_x);
	ptr->y_min = mouse_y + zoom * (ptr->y_min - mouse_y);
	ptr->y_max = mouse_y + zoom * (ptr->y_max - mouse_y);
}

int	zoom(int button, int x, int y, t_vals *ptr)
{
	if (button == 5 || button == 4)
	{
		zoom_calc(ptr, x, y, button);
		mlx_clear_window(ptr->init, ptr->win);
		if (ptr->temp == 1)
			my_mandelbrot(ptr);
		else if (ptr->temp == 2)
			my_julia(ptr);
		else if (ptr->temp == 3)
			my_burning_ship(ptr);
	}
	else if (button == 1)
		ptr->tr = 1;
	else if (button == 2)
		ptr->tr = 0;
	return (0);
}

int	move_julia(int x, int y, t_vals *ptr)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && ptr->tr == 0)
	{
		ptr->c_x = (double)x / WIDTH;
		ptr->c_y = (double)y / HEIGHT;
		my_julia(ptr);
	}
	return (0);
}
