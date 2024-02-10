/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:29:03 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/10 16:21:50 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	valid_param(char *av)
{
	while (*av)
	{
		if ((*av >= '0' && *av <= '9') || *av == '+'
			|| *av == '-' || *av == '.' || *av == ' ')
			av++;
		else
		{
			write(1, "The valid format is sign followed by number", 44);
			exit(1);
		}
	}
	return (1);
}

double	handle_param(char *av, int *res1)
{
	double	res2;
	int		k;

	res2 = 0;
	k = 0;
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
	res2 += (*res1);
	return (res2);
}
