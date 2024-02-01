/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:44:59 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/01 18:46:35 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_julia(t_data *img, gen_mlx *ptr)
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

