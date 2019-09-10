/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clover.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:28:17 by tpompon           #+#    #+#             */
/*   Updated: 2019/09/10 16:27:01 by tpompon          ###   ########.fr       */
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

static void		initialize_d(t_env *d)
{
	d->f->c_r = 0.285;
	d->f->c_i = 0.01;
	d->f->z_r = (d->f->x - WIN_WIDTH / 2.0)
		* (4.0 / WIN_WIDTH / d->zoom) + d->move_x;
	d->f->z_i = (d->f->y - WIN_HEIGHT / 2.0)
		* (4.0 / WIN_WIDTH / d->zoom) + d->move_y;
	d->f->iter = 0;
}

void			clover(t_env *d)
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
