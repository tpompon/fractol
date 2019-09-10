/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:23:08 by tpompon           #+#    #+#             */
/*   Updated: 2019/09/10 16:23:09 by tpompon          ###   ########.fr       */
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

static void		initialize_d(t_env *d)
{
	d->f->c_r = (d->f->x - WIN_WIDTH / 2.0)
		* (4.0 / WIN_WIDTH * 0.03 / d->zoom) - 1.755 + d->move_x;
	d->f->c_i = (d->f->y - WIN_HEIGHT / 2.0)
		* (4.0 / WIN_WIDTH * 0.03 / d->zoom) - 0.035 + d->move_y;
	d->f->z_r = 0;
	d->f->z_i = 0;
	d->f->iter = 0;
}

void			burning_ship(t_env *d)
{
	d->f->y = 0;
	while (d->f->y < WIN_HEIGHT)
	{
		d->f->x = 0;
		while (d->f->x < WIN_WIDTH)
		{
			initialize_d(d);
			while (fabs(d->f->z_r) * fabs(d->f->z_r) + fabs(d->f->z_i)
				* fabs(d->f->z_i) <= 4 && d->f->iter < d->max_iter)
			{
				d->f->tmp = (fabs(d->f->z_r) * fabs(d->f->z_r))
					- (fabs(d->f->z_i) * fabs(d->f->z_i)) + d->f->c_r;
				d->f->z_i = (2.0 * fabs(d->f->z_r)
					* fabs(d->f->z_i)) + d->f->c_i;
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
