/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:59:23 by tpompon           #+#    #+#             */
/*   Updated: 2019/05/10 13:09:53 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		get_color(int iter)
{
	int i;
	int *colors;

	i = iter % 16;
	if (!(colors = malloc(sizeof(int) * 16)))
		return (0);
	colors[0] = hexcolor(0, 0, 0);
	colors[1] = hexcolor(0, 0, 0);
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

void			julia(t_env *data)
{
	data->julia->y = 0;
	while (data->julia->y < WIN_HEIGHT)
	{
		data->julia->x = 0;
		while (data->julia->x < WIN_WIDTH)
		{
			data->julia->c_r = 0.285;
			data->julia->c_i = 0.01;
			data->julia->z_r = (data->julia->x - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH / data->zoom) + data->move_x;
			data->julia->z_i = (data->julia->y - WIN_HEIGHT / 2.0) * (4.0 / WIN_WIDTH / data->zoom) + data->move_y;
			data->julia->iter = 0;
			while (data->julia->z_r * data->julia->z_r + data->julia->z_i * data->julia->z_i <= 4 && data->julia->iter < data->max_iter)
			{
				data->julia->tmp = (data->julia->z_r * data->julia->z_r) - (data->julia->z_i * data->julia->z_i) + data->julia->c_r;
				data->julia->z_i = (2.0 * data->julia->z_r * data->julia->z_i) + data->julia->c_i;
				data->julia->z_r = data->julia->tmp;
				data->julia->iter++;
			}
			if (data->julia->iter < data->max_iter)
				ft_fill_pixel(data->julia->x, data->julia->y, get_color(data->julia->iter), data);
			else
				ft_fill_pixel(data->julia->x, data->julia->y, 0x000000, data);
			data->julia->x++;
		}
		data->julia->y++;
	}
}

