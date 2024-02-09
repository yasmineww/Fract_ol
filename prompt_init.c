/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:27:11 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/09 23:30:02 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	parsing(char *av)
{
	double	res2;
	int		res1;
	int		k;
	int		sign;

	k = 0;
	sign = 1;
	res1 = 0;
	res2 = 0;
	while ((*av >= 9 && *av <= 13) || *av == ' ')
		av++;
	if (*av == '-' || *av == '+')
	{
		if (*av == '-')
			sign *= -1;
	}
	av++;
	while (*av != '.' && *av != '\0')
	{
		if (*av >= '0' && *av <= '9')
		{
			res1 = (res1 * 10) + (*av - '0');
			av++;
		}
		else
			exit(1);
	}
	if (*av == '.')
		av++;
	while (*av != '\0')
	{
		if (*av >= '0' && *av <= '9')
		{
			res2 = (res2 * 10) + (*av - '0');
			av++;
			k++;
		}
		else
			exit(1);
	}
	res2 *= pow(10, -k);
	res2 += res1;
	return (res2 * sign);
}

void	initialize_vals(t_vals *ptr)
{
	ptr->x_min = -2;
	ptr->x_max = 2;
	ptr->y_min = -2;
	ptr->y_max = 2;
	ptr->zoom = 1.0;
	ptr->c_x = 0.285;
	ptr->c_y = 0.01;
	ptr->tr = 0;
	ptr->move_x = 0.0;
	ptr->move_y = 0.0;
	ptr->color = 0XFFB6CB;
	ptr->max = 20;
}

void	initialize_mlx(t_vals *ptr)
{
	ptr->init = mlx_init();
	if (!ptr->init)
		exit(1);
	ptr->win = mlx_new_window(ptr->init, WIDTH, HEIGHT, "My Pink Fractol");
	if (!ptr->win)
		exit(1);
	ptr->img = mlx_new_image(ptr->init, WIDTH, HEIGHT);
	if (!ptr->img)
	{
		mlx_destroy_window(ptr->init, ptr->win);
		exit(1);
	}
	ptr->addr = mlx_get_data_addr(ptr->img, &ptr->bpp, &ptr->line_length,
			&ptr->endian);
	if (!ptr->addr)
		exit(1);
	initialize_vals(ptr);
	mlx_hook(ptr->win, 02, 0, buttons, ptr);
	mlx_hook(ptr->win, 04, 0, zoom, ptr);
	mlx_hook(ptr->win, 17, 0, esc, ptr);
}

int main (int ac, char **av)
{
	t_vals	ptr;

	initialize_mlx(&ptr);
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "M"))
		{
			ptr.temp = 1;
			my_mandelbrot(&ptr);
		}
		else if (!ft_strcmp(av[1], "J"))
		{
			ptr.temp = 2;
			my_julia(&ptr);
		}
		else if (!ft_strcmp(av[1], "S"))
		{
			ptr.temp = 3;
			my_burning_ship(&ptr);
		}
		else
		{
			write(1, "Please press M, J or S", 23);
			exit(0);
		}
	}
	else if (ac >= 2 && !ft_strcmp(av[1], "J"))
	{
		valid_param(av[2]);
		valid_param(av[3]);
		ptr.c_x = parsing(av[2]);
		ptr.c_y = parsing(av[3]);
		ptr.temp = 2;
		my_julia(&ptr);
	}
	return (0);
}
