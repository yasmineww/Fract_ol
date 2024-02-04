/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:44:59 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/04 23:01:51 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_julia(all_vals *ptr)
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
			my_math_julia(&comp, ptr, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ptr->init, ptr->win, ptr->img, 0, 0);
	mlx_hook(ptr->win, 04, 0, zoom, ptr);
	while ()
	{
		mlx_hook(ptr->win, 6, 0, move_julia, ptr);	
	}
	mlx_hook(ptr->win, 2, 0, buttons, ptr);
	mlx_hook(ptr->win, 17, 0, esc, ptr);
	mlx_loop(ptr->init);	
}

void	my_math_julia(n_complex *comp, all_vals *ptr, int x, int y)
{
	n_complex	z;
	n_complex	c;
	double		temp_z;
	int			i;

	z.x = comp->x;
	z.y = comp->y;
	c.x = ptr->c_x;
	c.y = ptr->c_y;
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

// void	color_pixel_julia(t_data *img, int x, int y, int i)
// {
// 	int R = (i * 150) % 256;
        
//     int G = (i * 80) % 256;
        
//     int B = (i * 80) % 256;

//     int color = (R << 16) | (G << 8) | B;
        
//     my_pixel_put(img, x, y, color); 
// }