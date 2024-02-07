/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:19:33 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/06 20:16:27 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_burning_ship(all_vals *ptr)
{
	int			x;
	int			y;
	n_complex	comp;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			comp = mapping_px(&comp, x, y, ptr);
			my_burning_math(&comp, ptr, x, y);
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

void	my_burning_math(n_complex *comp, all_vals *ptr, int x, int y)
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
		z.y = fabs(2 * z.x * z.y) + c.y;
		z.x = temp_z;
		if ((z.x * z.x) + (z.y * z.y) >= 4)
			break ;
	}
	if (i == MAX_ITER)
	{
		my_pixel_put(ptr, x, y, 0x000000);
	}
	else
		color_pixel_ship(ptr, x, y, i);
}

void	color_pixel_ship(all_vals *ptr, int x, int y, int i)
{
	int	color;

	ptr->R = (i * 255) % 256;
	ptr->G = (i * 219) % 256;
	ptr->B = (i * 0) % 256;
	color = (ptr->R << 16) | (ptr->G << 8) | ptr->B;
	my_pixel_put(ptr, x, y, color);
}
