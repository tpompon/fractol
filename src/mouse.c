/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:50:37 by tpompon           #+#    #+#             */
/*   Updated: 2019/09/10 16:52:45 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mouse_julia(t_env *data)
{
	if (data->julia_mouse == 0)
		data->julia_mouse = 1;
	else if (data->julia_mouse == 1)
		data->julia_mouse = 0;
	ft_redo(data);
}

int		mouse_move(int x, int y, void *param)
{
	t_env *data;

	data = param;
	if (data->select == JULIA && data->julia_mouse == 1)
	{
		if (x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT)
		{
			data->f->c_r = (x - WIN_WIDTH / 2.0) / (WIN_WIDTH / 4.0);
			data->f->c_i = (y - WIN_HEIGHT / 2.0) / (WIN_HEIGHT / 4.0);
		}
	}
	ft_redo(data);
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_env *data;

	(void)x;
	(void)y;
	data = param;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		ft_zoom(button, data);
	if (button == LEFT_CLICK && data->select == JULIA)
		ft_mouse_julia(data);
	return (0);
}
