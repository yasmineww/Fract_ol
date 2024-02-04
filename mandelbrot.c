/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:28:11 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/04 19:34:58 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(all_vals *ptr, int x, int y, int color) //protect x and y
{
	char	*dst;

	dst = ptr->addr + (y * ptr->line_length + x * (ptr->bpp / 8));
	*(unsigned int*)dst = color;
}

void	color_pixel(all_vals *ptr, int x, int y, int i)
{
	int R = (i * 255) % 256;
        
    int G = (i * 182) % 256;
        
    int B = (i * 203) % 256;

    int color = (R << 16) | (G << 8) | B;
        
    my_pixel_put(ptr, x, y, color); 
}

void	my_math(n_complex *comp, all_vals *ptr, int x, int y)
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
	while (++i < MAX_ITER)
	{
		temp_z = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp_z;
		if ((z.x * z.x) + (z.y * z.y) >= 4)//pythagore
			break;
	}
	if (i == MAX_ITER)
	{
		my_pixel_put(ptr, x, y, 0x000000);
	}
	else
		color_pixel(ptr, x, y, i);
}

n_complex	mapping_px(n_complex *comp, int x, int y, all_vals *ptr)
{
	comp->x = (x * (ptr->x_max - ptr->x_min) / WIDTH + ptr->x_min);
	comp->y = (y * (ptr->y_max - ptr->y_min) / HEIGHT + ptr->y_min);
	return (*comp);
}

void	my_mandelbrot(all_vals *ptr)
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
		 	comp = mapping_px(&comp, x, y, ptr);
			my_math(&comp, ptr, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ptr->init, ptr->win, ptr->img, 0, 0);
	mlx_hook(ptr->win, 04, 0, zoom, ptr);
	mlx_hook(ptr->win, 2, 0, buttons, ptr);//for esc button
	mlx_hook(ptr->win, 17, 0, esc, ptr);//for the red destroy button on the window
	mlx_loop(ptr->init);
}
