/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:28:11 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/01 18:57:32 by ymakhlou         ###   ########.fr       */
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
	{
		printf("%d\n", i);
		my_pixel_put(img, x, y, 0x00FF00);
	}
	else
		color_pixel(img, x, y, i);
}

n_complex	mapping_px(n_complex *comp, int x, int y)
{
	comp->x = x * ((0.9 + 2) / WIDTH) - 2;
	comp->y = y * ((1.5 + 1.5) / HEIGHT) - 1.5;
	return (*comp);
}

void	my_mandelbrot(t_data *img, gen_mlx *ptr)
{
	int			x;
	int			y;
	n_complex	comp;
	
	y = 0;
	while(y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
		 	comp = mapping_px(&comp, x, y);
			my_math(&comp, img, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ptr->init, ptr->win, img->img, 0, 0);
	mlx_loop(ptr->init);	
}

