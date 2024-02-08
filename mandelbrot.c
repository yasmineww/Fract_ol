/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:28:11 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/08 10:51:07 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_vals *ptr, int x, int y, int color)
{
	char	*dst;

	dst = ptr->addr + (y * ptr->line_length + x * (ptr->bpp / 8));
	*(unsigned int *)dst = color;
}

void	my_math(t_complex *comp, t_vals *ptr, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		temp_z;

	z.x = 0;
	z.y = 0;
	c.x = comp->x + ptr->move_x;
	c.y = comp->y + ptr->move_y;
	ptr->iter = 0;
	while (++(ptr->iter) < ptr->max)
	{
		temp_z = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp_z;
		if ((z.x * z.x) + (z.y * z.y) >= 4)
			break ;
	}
	if (ptr->iter == ptr->max)
		my_pixel_put(ptr, x, y, 0x000000);
	else
		my_pixel_put(ptr, x, y, ptr->color * ptr->iter);
}

t_complex	mapping_px(t_complex *comp, int x, int y, t_vals *ptr)
{
	comp->x = (x * (ptr->x_max - ptr->x_min) / WIDTH) + ptr->x_min;
	comp->y = (y * (ptr->y_max - ptr->y_min) / HEIGHT) + ptr->y_min;
	return (*comp);
}

void	my_mandelbrot(t_vals *ptr)
{
	int			x;
	int			y;
	t_complex	comp;

	y = 0;
	while (y < HEIGHT)
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
	mlx_loop(ptr->init);
}
