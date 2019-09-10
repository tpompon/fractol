/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:17:44 by tpompon           #+#    #+#             */
/*   Updated: 2019/09/10 16:19:44 by tpompon          ###   ########.fr       */
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

static void		initialize_d(t_env *d)
{
	d->f->c_r = (d->f->x - WIN_WIDTH / 2.0)
		* (4.0 / WIN_WIDTH / d->zoom) + d->move_x;
	d->f->c_i = (d->f->y - WIN_HEIGHT / 2.0)
		* (4.0 / WIN_WIDTH / d->zoom) + d->move_y;
	d->f->z_r = 0;
	d->f->z_i = 0;
	d->f->iter = 0;
}

void			mandelbrot(t_env *d)
{
	d->f->y = 0;
	while (d->f->y < WIN_HEIGHT)
	{
		d->f->x = 0;
		while (d->f->x < WIN_WIDTH)
		{
			initialize_d(d);
			while (d->f->z_r * d->f->z_r + d->f->z_i * d->f->z_i <= 4
				&& d->f->iter < d->max_iter)
			{
				d->f->tmp = (d->f->z_r * d->f->z_r)
					- (d->f->z_i * d->f->z_i) + d->f->c_r;
				d->f->z_i = (2.0 * d->f->z_r * d->f->z_i) + d->f->c_i;
				d->f->z_r = d->f->tmp;
				d->f->iter++;
			}
			if (d->f->iter < d->max_iter)
				ft_fill_pixel(d->f->x, d->f->y, get_color(d->f->iter), d);
			else
				ft_fill_pixel(d->f->x, d->f->y, 0x000000, d);
			d->f->x++;
		}
		d->f->y++;
	}
}
