/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:28:05 by tpompon           #+#    #+#             */
/*   Updated: 2019/04/13 21:29:49 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		get_color_m(int iter)
{
	int i;
	int *colors;

	i = iter % 16;
	if (!(colors = malloc(sizeof(int) * 16)))
		return (0);
	colors[0] = hexcolor(66, 30, 15);
	colors[1] = hexcolor(25, 7, 26);
	colors[2] = hexcolor(9, 1, 47);
	colors[3] = hexcolor(4, 4, 73);
	colors[4] = hexcolor(0, 7, 100);
	colors[5] = hexcolor(12, 44, 138);
	colors[6] = hexcolor(24, 82, 177);
	colors[7] = hexcolor(57, 125, 209);
	colors[8] = hexcolor(134, 181, 229);
	colors[9] = hexcolor(211, 236, 248);
	colors[10] = hexcolor(241, 233, 191);
	colors[11] = hexcolor(248, 201, 95);
	colors[12] = hexcolor(255, 170, 0);
	colors[13] = hexcolor(204, 128, 0);
	colors[14] = hexcolor(153, 87, 0);
	colors[15] = hexcolor(106, 52, 3);
	free(colors);
	return (colors[i]);
}

void			mandelbrot(t_env *data)
{
	int		x;
	int		y;
	int		iter;
	double	c_real;
	double	c_imag;
	double	tmp;
	t_point p;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			c_real = (x - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH / data->zoom) + data->move_x;
			c_imag = (y - WIN_HEIGHT / 2.0) * (4.0 / WIN_WIDTH / data->zoom) + data->move_y;
			p = init_point(0, 0);
			iter = 0;
			while (p.x * p.x + p.y * p.y <= 4 && iter < data->max_iter)
			{
				tmp = (p.x * p.x) - (p.y * p.y) + c_real;
				p.y = (2.0 * p.x * p.y) + c_imag;
				p.x = tmp;
				iter++;
			}
			if (iter < data->max_iter)
				ft_fill_pixel(x, y, get_color_m(iter), data);
			else
				ft_fill_pixel(x, y, 0x000000, data);
			x++;
		}
		y++;
	}
}
