/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:19:33 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/14 10:58:58 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_burning_ship(t_vals *ptr)
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
			my_burning_math(&comp, ptr, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ptr->init, ptr->win, ptr->img, 0, 0);
	mlx_hook(ptr->win, 04, 0, zoom, ptr);
	mlx_hook(ptr->win, 2, 0, buttons, ptr);
	mlx_hook(ptr->win, 17, 0, esc, ptr);
	mlx_loop(ptr->init);
}

void	my_burning_math(t_complex *comp, t_vals *ptr, int x, int y)
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
		z.y = fabs(2 * z.x * z.y) + c.y;
		z.x = temp_z;
		if ((z.x * z.x) + (z.y * z.y) >= 4)
			break ;
	}
	if (ptr->iter == ptr->max)
		my_pixel_put(ptr, x, y, 0x000000);
	else
		my_pixel_put(ptr, x, y, ptr->color * ptr->iter);
}
