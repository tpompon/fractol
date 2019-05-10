/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:38:50 by tpompon           #+#    #+#             */
/*   Updated: 2019/05/10 11:52:37 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			hexcolor(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void		ft_fill_pixel(int x, int y, int color, t_env *data)
{
	int i;

	i = y * WIN_WIDTH + x;
	data->img_str[i] = color;
}

void		ft_fill_img_black(t_env *data)
{
	int i;

	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH)
	{
		data->img_str[i] = BLACK;
		i++;
	}
}
