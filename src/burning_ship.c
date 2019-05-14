/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:20:51 by tpompon           #+#    #+#             */
/*   Updated: 2019/05/13 13:02:39 by tpompon          ###   ########.fr       */
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
	colors[0] = hexcolor(14, 0, 0);
	colors[1] = hexcolor(42, 1, 0);
	colors[2] = hexcolor(71, 3, 0);
	colors[3] = hexcolor(101, 4, 0);
	colors[4] = hexcolor(136, 5, 0);
	colors[5] = hexcolor(141, 14, 0);
	colors[6] = hexcolor(147, 22, 0);
	colors[7] = hexcolor(156, 33, 0);
	colors[8] = hexcolor(164, 41, 0);
	colors[9] = hexcolor(176, 52, 0);
	colors[10] = hexcolor(255, 57, 0);
	colors[11] = hexcolor(255, 163, 49);
	free(colors);
	return (colors[i]);
}

void			burning_ship(t_env *data)
{
	data->f->y = 0;
	while (data->f->y < WIN_HEIGHT)
	{
		data->f->x = 0;
		while (data->f->x < WIN_WIDTH)
		{
			data->f->c_r = (data->f->x - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH * 0.03 / data->zoom) - 1.755 + data->move_x;
			data->f->c_i = (data->f->y - WIN_HEIGHT / 2.0) * (4.0 / WIN_WIDTH * 0.03 / data->zoom) - 0.035 + data->move_y;
			data->f->z_r = 0;
			data->f->z_i = 0;
			data->f->iter = 0;
			while (fabs(data->f->z_r) * fabs(data->f->z_r) + fabs(data->f->z_i) * fabs(data->f->z_i) <= 4 && data->f->iter < data->max_iter)
			{
				data->f->tmp = (fabs(data->f->z_r) * fabs(data->f->z_r)) - (fabs(data->f->z_i) * fabs(data->f->z_i)) + data->f->c_r;
				data->f->z_i = (2.0 * fabs(data->f->z_r) * fabs(data->f->z_i)) + data->f->c_i;
				data->f->z_r = data->f->tmp;
				data->f->iter++;
			}
			if (data->f->iter < data->max_iter)
				ft_fill_pixel(data->f->x, data->f->y, get_color(data->f->iter), data);
			else
				ft_fill_pixel(data->f->x, data->f->y, 0x000000, data);
			data->f->x++;
		}
		data->f->y++;
	}
}
