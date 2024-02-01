/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:26:38 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/01/30 14:14:21 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	ft_putchar(char c)
// {
// 	write (1, &c, 1);
// }

// int	deal_key(int key, void *param)
// {
// 	printf("%d\n", key);
// 	if (key == 53)
// 	{
// 		mlx_destroy_image()
// 		exit(0);
// 	}
// 	return (0);
// }

int	main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			i;
	n_complex	z;
	n_complex	c;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = 5;
	c.y = 5;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "my_mlx");
	while (i < 100)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 400 + i, 400 , 0xFF99CC);
		mlx_pixel_put(mlx_ptr, win_ptr, 400 , 400 - i, 0xFF99CC);
		mlx_pixel_put(mlx_ptr, win_ptr, 500, 400 - i, 0xFF99CC);
		mlx_pixel_put(mlx_ptr, win_ptr, 400 + i , 300, 0xFF99CC);
		i++;
	}
	// mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop (mlx_ptr);
}
