/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:20:51 by tpompon           #+#    #+#             */
/*   Updated: 2019/05/10 13:22:44 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		get_color(int iter)
{
	int i;
	int *colors;

	i = iter % 12;
	if (!(colors = malloc(sizeof(int) * 12)))
		return (0);
	colors[0] = hexcolor(0, 14, 0);
	colors[1] = hexcolor(1, 42, 0);
	colors[2] = hexcolor(3, 71, 0);
	colors[3] = hexcolor(4, 101, 0);
	colors[4] = hexcolor(5, 136, 0);
	colors[5] = hexcolor(14, 141, 0);
	colors[6] = hexcolor(22, 147, 0);
	colors[7] = hexcolor(33, 156, 0);
	colors[8] = hexcolor(41, 164, 0);
	colors[9] = hexcolor(52, 176, 0);
	colors[10] = hexcolor(57, 255, 0);
	colors[11] = hexcolor(163, 255, 49);
	free(colors);
	return (colors[i]);
}

void			burning_ship(t_env *data)
{
	data->burning_ship->y = 0;
	while (data->burning_ship->y < WIN_HEIGHT)
	{
		data->burning_ship->x = 0;
		while (data->burning_ship->x < WIN_WIDTH)
		{
			data->burning_ship->c_r = (data->burning_ship->x - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH * 0.0001 / data->zoom) - 1.53009 + data->move_x;
			data->burning_ship->c_i = (data->burning_ship->y - WIN_HEIGHT / 2.0) * (4.0 / WIN_WIDTH * 0.0001 / data->zoom) - 0.0001 + data->move_y;
			data->burning_ship->z_r = 0;
			data->burning_ship->z_i = 0;
			data->burning_ship->iter = 0;
			while (fabs(data->burning_ship->z_r) * fabs(data->burning_ship->z_r) + fabs(data->burning_ship->z_i) * fabs(data->burning_ship->z_i) <= 4 && data->burning_ship->iter < data->max_iter)
			{
				data->burning_ship->tmp = (fabs(data->burning_ship->z_r) * fabs(data->burning_ship->z_r)) - (fabs(data->burning_ship->z_i) * fabs(data->burning_ship->z_i)) + data->burning_ship->c_r;
				data->burning_ship->z_i = (2.0 * fabs(data->burning_ship->z_r) * fabs(data->burning_ship->z_i)) + data->burning_ship->c_i;
				data->burning_ship->z_r = data->burning_ship->tmp;
				data->burning_ship->iter++;
			}
			if (data->burning_ship->iter < data->max_iter)
				ft_fill_pixel(data->burning_ship->x, data->burning_ship->y, get_color(data->burning_ship->iter), data);
			else
				ft_fill_pixel(data->burning_ship->x, data->burning_ship->y, 0x000000, data);
			data->burning_ship->x++;
		}
		data->burning_ship->y++;
	}
}
