/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clover.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:28:17 by tpompon           #+#    #+#             */
/*   Updated: 2019/05/13 17:02:27 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		get_color(int iter)
{
	int i;
	int *colors;

	i = iter % 5;
	if (!(colors = malloc(sizeof(int) * 5)))
		return (0);
	colors[0] = hexcolor(255, 0, 193);
	colors[1] = hexcolor(150, 0, 255);
	colors[2] = hexcolor(73, 0, 255);
	colors[3] = hexcolor(0, 184, 255);
	colors[4] = hexcolor(0, 255, 249);
	free(colors);
	return (colors[i]);
}

void			clover(t_env *data)
{
	data->f->y = 0;
	while (data->f->y < WIN_HEIGHT)
	{
		data->f->x = 0;
		while (data->f->x < WIN_WIDTH)
		{
			data->f->c_r = 0.285;
			data->f->c_i = 0.01;
			data->f->z_r = (data->f->x - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH / data->zoom) + data->move_x;
			data->f->z_i = (data->f->y - WIN_HEIGHT / 2.0) * (4.0 / WIN_WIDTH / data->zoom) + data->move_y;
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

