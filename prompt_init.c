/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:27:11 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/01 18:51:06 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	puts("ok0");
	if (!img->img)
		exit(1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	if (!img->addr)
		exit(1);
}

// int main (int ac, char **av)
// {
// 	gen_mlx	ptr;
// 	t_data	img;

// 	if (ac == 2)
// 	{
// 		if (av[1] == "M")
// 		{
// 			initialize_mlx(&ptr, &img);
// 			my_mandelbrot(&img, &ptr);
// 		}
// 		else if (av[1] == "J")
// 		{
// 			initialize_mlx(&ptr, &img);
// 			my_julia(img);
// 		}
// 	}
// 	return (0);
// }

int main (void)
{
	gen_mlx		ptr;
	t_data		img;

	initialize_mlx(&ptr, &img);
	my_mandelbrot(&img, &ptr);
	return (0);
}