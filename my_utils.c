/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:29:03 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/09 23:19:23 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	valid_param(char *av)
{
	while (*av)
	{
		if (*av >= '0' && *av <= '9')
			av++;
		else if (*av == '+')
			av++;
		else if (*av == '-')
			av++;
		else if (*av == '.')
			av++;
		else if (*av == ' ')
			av++;
		else
		{
			write(1, "The valid format is sign followed by number", 44);
			exit(0);
		}
	}
}
