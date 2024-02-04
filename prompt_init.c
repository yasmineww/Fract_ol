/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:27:11 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/04 22:22:08 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_vals(all_vals *ptr)
{
	ptr->x_min = -1.999999;
	ptr->x_max = 2;
	ptr->y_min = -1.999999;
	ptr->y_max = 2;
	ptr->zoom = 1.1;
	ptr->c_x = -0.745429;
	ptr->c_y = 0.05;
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
}

int main (int ac, char **av)
{
	all_vals	ptr;

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
			//parsing();
			write(1, "Available fractals are Mandel, Julia and Ship. Please press m, j or s", 70);
		}
	}
	return (0);
}
