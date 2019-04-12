/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:28:05 by tpompon           #+#    #+#             */
/*   Updated: 2019/04/12 17:58:41 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_env *data)
{
	int		row;
	int		col;
	int		iter;
	double	c_re;
	double	c_im;
	double	x;
	double	y;
	double	x_new;

	row = 0;
	while (row < WIN_HEIGHT)
	{
		col = 0;
		while (col < WIN_WIDTH)
		{
			c_re = (col - WIN_WIDTH / 2.0) * 4.0 / WIN_WIDTH;
			c_im = (row - WIN_HEIGHT / 2.0) * 4.0 / WIN_WIDTH;
			x = 0;
			y = 0;
			iter = 0;
			while (x * x + y * y <= 4 && iter < MAX_ITER)
			{
				x_new = x * x - y * y + c_re;
				y = 2 * x * y + c_im;
				x = x_new;
				iter++;
			}
			if (iter < MAX_ITER)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, col, row, hexcolor(iter, 0, 0));
			else
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, col, row, 0x000000);
			col++;
		}
		row++;
	}
}
