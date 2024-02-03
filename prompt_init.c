/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:27:11 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/02 20:49:13 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	key_hook(int keycode, gen_mlx *vars)
// {
// 	printf("Hello from key_hook!\n");
// 	return (0);
// }

void	initialize_mlx(gen_mlx *ptr, t_data *img)
{
	ptr->init = mlx_init();
	//ptr->init = NULL;
	if (!ptr->init)
		exit(1);
	ptr->win = mlx_new_window(ptr->init, WIDTH, HEIGHT, "Mandelbrot");
	if (!ptr->win)
		exit(1);
	img->img = mlx_new_image(ptr->init, WIDTH, HEIGHT);
	if (!img->img)
		exit(1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	if (!img->addr)
		exit(1);
}

int main (int ac, char **av)
{
	gen_mlx	ptr;
	t_data	img;

	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "M"))
		{
			initialize_mlx(&ptr, &img);
			my_mandelbrot(&img, &ptr);
		}
		else if (!ft_strcmp(av[1], "J"))
		{
			initialize_mlx(&ptr, &img);
			my_julia(&img, &ptr);
		}
		else if (!ft_strcmp(av[1], "S"))
		{
			initialize_mlx(&ptr, &img);
			my_burning_ship(&img, &ptr);
		}
		else
		{
			write(1, "Available fractals are Mandel, Julia and Ship. Please press m, j or s", 70);
		}
	}
	return (0);
}
