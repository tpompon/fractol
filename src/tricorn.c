/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:28:05 by tpompon           #+#    #+#             */
/*   Updated: 2019/05/13 13:06:50 by tpompon          ###   ########.fr       */
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

void			tricorn(t_env *data)
{
	data->f->y = 0;
	while (data->f->y < WIN_HEIGHT)
	{
		data->f->x = 0;
		while (data->f->x < WIN_WIDTH)
		{
			data->f->c_r = (data->f->x - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH / data->zoom) + data->move_x;
			data->f->c_i = (data->f->y - WIN_HEIGHT / 2.0) * (4.0 / WIN_WIDTH / data->zoom) + data->move_y;
			data->f->z_r = 0;
			data->f->z_i = 0;
			data->f->iter = 0;
			while (data->f->z_r * data->f->z_r + data->f->z_i * data->f->z_i <= 4 && data->f->iter < data->max_iter)
			{
				data->f->tmp = (data->f->z_r * data->f->z_r) - (data->f->z_i * data->f->z_i) + data->f->c_r;
				data->f->z_i = (-2.0 * data->f->z_r * data->f->z_i) + data->f->c_i;
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
