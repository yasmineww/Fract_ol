/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:19:33 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/03 21:12:08 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_burning_ship(t_data *img, gen_mlx *ptr)
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
			my_burning_math(&comp, img, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ptr->init, ptr->win, img->img, 0, 0);
	mlx_loop(ptr->init);	
}

void	my_burning_math(n_complex *comp, t_data *img, int x, int y)
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
		if ((z.x * z.x) + (z.y * z.y) >= 5)//pythagore
			break;
	}
	if (i == MAX_ITER)
	{
		my_pixel_put(img, x, y, 0x000000);
	}
	else
		color_pixel_ship(img, x, y, i);
}

void	color_pixel_ship(t_data *img, int x, int y, int i)
{
	int R = (i * 215) % 256;
        
    int G = (i * 0) % 256;
        
    int B = (i * 0) % 256;

    int color = (R << 16) | (G << 8) | B;
        
    my_pixel_put(img, x, y, color); 
}
