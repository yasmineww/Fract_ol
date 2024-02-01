/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:28:11 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/01 02:14:58 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mandelbrot(int x, int y)
{
	int	x;
	int	y;
	n_complex	*comp;
	
	y = 0;
	// comp->x = -2.0;
	// comp->y= -2.0;
	while(y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			comp = mapping_px(comp, x, y);
			my_math(comp, x, y);
			x++;
		}
		y++;
	}
}

void	color_pixel(t_data *img, int x, int y, int i)
{
	int R = (i * 3) % 256;
        
    int G = (i * 9) % 256;
        
    int B = (i * 12) % 256;

    int color = (R << 16) | (G << 8) | B;
        
    my_pixel_put(img, x, y, color); 
}

void	my_math(n_complex *comp, int x, int y)
{
	n_complex	z;
	n_complex	c;
	t_data		*img;
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
	comp->x = x * (new_max - new_min / WIDTH) + new_min;
	comp->y = y * (new_max - new_min / HEIGHT) + new_min;
	return (comp);
}

void	my_pixel_put(t_data *img, int x, int y, int color) //protect x and y
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	initialize_mlx(gen_mlx *ptr, t_data *img)
{
	int i;
	int iter;

	i = 0;
	iter = 100;
	ptr->init = mlx_init();
	//ptr->init = NULL;
	if (!ptr->init)
		exit(1);
	ptr->win = mlx_new_window(ptr->init, HEIGHT, WIDTH, "Mandelbrot");
	if (!ptr->win)
		exit(1);
	img->img = mlx_new_image(ptr->init, HEIGHT, WIDTH);
	if (!img->img)
		exit(1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	if (!img->addr)
		exit(1);
	
	//mlx_put_image_to_window(ptr->init, ptr->win, img->img, 0, 0);
	//mlx_loop(ptr->init);
}

int main (int ac, char **av)
{
	gen_mlx		ptr;
	t_data		img;

	initialize_mlx(&ptr, &img);
}
