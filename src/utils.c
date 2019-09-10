/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:38:50 by tpompon           #+#    #+#             */
/*   Updated: 2019/09/10 16:49:47 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			hexcolor(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void		ft_fill_pixel(int x, int y, int color, t_env *data)
{
	int i;

	i = y * WIN_WIDTH + x;
	data->img_str[i] = color;
}

void		ft_perror(void)
{
	perror("\033[0;31mError\033[0m ");
	exit(0);
}

void		ft_usage(void)
{
	ft_putendl("\nUsage: ./fractol [map]\n\n\
	* Maps available:\n\n\
	-> Mandelbrot\n\
	-> Julia\n\
	-> Burning_Ship\n\
	-> Tricorn\n\
	-> Clover\n\
	");
	exit(0);
}

void		format_name(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	str[0] = ft_toupper(str[0]);
}
