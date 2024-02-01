/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:28:11 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/01 17:48:20 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_data *img, int x, int y, int color) //protect x and y
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	color_pixel(t_data *img, int x, int y, int i)
{
	int R = (i * 3) % 256;
        
    int G = (i * 9) % 256;
        
    int B = (i * 12) % 256;

    int color = (R << 16) | (G << 8) | B;
        
    my_pixel_put(img, x, y, color); 
}

void	my_math(n_complex *comp, t_data *img, int x, int y)
{
	n_complex	z;
	n_complex	c;
	double		temp_z;
	int			i;

	z.x = 0;
	z.y = 0;
	c.x = comp->x;
	c.y = comp->y;
	i = 0;
	while (i++ < MAX_ITER)
	{
		temp_z = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp_z;
		if ((z.x * z.x) + (z.y * z.y) >= 20)//pythagore
			break;
	}
	if (i == MAX_ITER)
		my_pixel_put(img, x, y, 0x000000);
	else
		color_pixel(img, x, y, i);
}

n_complex	*mapping_px(n_complex *comp, int x, int y)
{
	comp->x = x * (2 - (-2) / WIDTH) + -2;
	comp->y = y * (2 - (-2) / HEIGHT) + -2;
	return (comp);
}

void	my_mandelbrot(t_data *img, gen_mlx *ptr)
{
	int			x;
	int			y;
	n_complex	*comp;
	
	y = 0;
	while(y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			comp = mapping_px(comp, x, y);
			my_math(comp, img, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ptr->init, ptr->win, img->img, 0, 0);
	mlx_loop(ptr->init);	
}

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

int main (void)
{
	gen_mlx		*ptr;
	t_data		*img;

	initialize_mlx(ptr, img);
	puts("okfin");
	my_mandelbrot(img, ptr);
	return (0);
}
// int main (int ac, char **av)
// {
// 	gen_mlx		*ptr;
// 	t_data		*img;

// 	if (ac == 2)
// 	{
// 		if (av[1] == "M")
// 		{
// 			initialize_mlx(&ptr, &img);
// 			my_mandelbrot(img, ptr);
// 		}
// 		else if (av[1] == "J")
// 		{
// 			initialize_mlx(&ptr, &img);
// 			my_julia(img);
// 		}
// 	}
// 	return (0);
// }
