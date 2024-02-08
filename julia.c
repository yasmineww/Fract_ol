/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:44:59 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/08 11:01:58 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_julia(t_vals *ptr)
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
			my_math_julia(&comp, ptr, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ptr->init, ptr->win, ptr->img, 0, 0);
	mlx_hook(ptr->win, 04, 0, zoom, ptr);
	mlx_hook(ptr->win, 6, 0, move_julia, ptr);
	mlx_hook(ptr->win, 2, 0, buttons, ptr);
	mlx_hook(ptr->win, 17, 0, esc, ptr);
	mlx_loop(ptr->init);
}

void	my_math_julia(t_complex *comp, t_vals *ptr, int x, int y)
{
	t_complex	z;
	double		temp_z;

	z.x = comp->x + ptr->move_x;
	z.y = comp->y + ptr->move_y;
	ptr->iter = 0;
	while (++(ptr->iter) < ptr->max)
	{
		temp_z = (z.x * z.x) - (z.y * z.y) + ptr->c_x;
		z.y = 2 * z.x * z.y + ptr->c_y;
		z.x = temp_z;
		if ((z.x * z.x) + (z.y * z.y) >= 4)
			break ;
	}
	if (ptr->iter == ptr->max)
	{
		my_pixel_put(ptr, x, y, 0x000000);
	}
	else
		my_pixel_put(ptr, x, y, ptr->color * ptr->iter);
}
