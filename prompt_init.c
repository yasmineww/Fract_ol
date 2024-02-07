/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:27:11 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/06 20:20:09 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parsing()
{
	
}

void	initialize_vals(all_vals *ptr)
{
	ptr->x_min = -2;
	ptr->x_max = 2;
	ptr->y_min = -2;
	ptr->y_max = 2;
	ptr->zoom = 1.0;
	ptr->c_x = 0.285;
	ptr->c_y = 0.01;
	ptr->tr = 0;
	ptr->iter = 0;
	ptr->move_x = 0.0;
	ptr->move_y = 0.0;
	ptr->R = 0;
	ptr->G = 0;
	ptr->B = 0;
}

void	initialize_mlx(all_vals *ptr)
{
	ptr->init = mlx_init();
	//ptr->init = NULL;
	if (!ptr->init)
		exit(1);
	ptr->win = mlx_new_window(ptr->init, WIDTH, HEIGHT, "Mandelbrot");
	if (!ptr->win)
		exit(1);
	ptr->img = mlx_new_image(ptr->init, WIDTH, HEIGHT);
	if (!ptr->img)
	{
		mlx_destroy_window(ptr->init, ptr->win);
		exit(1);
	}
	ptr->addr = mlx_get_data_addr(ptr->img, &ptr->bpp, &ptr->line_length, &ptr->endian);
	if (!ptr->addr)
		exit(1);
	initialize_vals(ptr);
	mlx_hook(ptr->win, 02, 0, buttons, ptr);//for esc button
	mlx_hook(ptr->win, 04, 0, zoom, ptr);
	mlx_hook(ptr->win, 17, 0, esc, ptr);//for the red destroy button on the window
}

int main (int ac, char **av)
{
	all_vals	ptr;

	if (HEIGHT < 0 && HEIGHT > 2000 && WIDTH < 0 && WIDTH > 2000)
		exit (1);
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "M"))
		{
			ptr.temp = 1;
			initialize_mlx(&ptr);
			my_mandelbrot(&ptr);
		}
		else if (!ft_strcmp(av[1], "J"))
		{
			ptr.temp = 2;
			initialize_mlx(&ptr);
			my_julia(&ptr);
		}
		else if (!ft_strcmp(av[1], "S"))
		{
			ptr.temp = 3;
			initialize_mlx(&ptr);
			my_burning_ship(&ptr);
		}
		else
		{
			//parsing(&av);
			write(1, "Available fractals are Mandel, Julia and Ship. Please press m, j or s", 70);
		}
	}
	return (0);
}
