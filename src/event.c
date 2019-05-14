/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:26:18 by tpompon           #+#    #+#             */
/*   Updated: 2019/05/14 14:30:18 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_redo(t_env *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_display(data);
}

void	ft_max_iter(int keycode, t_env *data)
{
	if (keycode == ITER_PLUS && data->max_iter < 499)
		data->max_iter += 10;
	if (keycode == ITER_MINUS && data->max_iter > 1)
		data->max_iter -= 10;
	ft_redo(data);
}

void	ft_move(int keycode, t_env *data)
{
	if (keycode == DOWN)
		data->move_y -= 0.1;
	if (keycode == UP)
		data->move_y += 0.1;
	if (keycode == LEFT)
		data->move_x += 0.1;
	if (keycode == RIGHT)
		data->move_x -= 0.1;
	ft_redo(data);
}

void	ft_zoom(int keycode, t_env *data)
{
	if (keycode == PLUS || keycode == SCROLL_UP)
	{
		data->zoom += 0.1;
		data->max_iter += 1;
	}
	if (keycode == MINUS || keycode == SCROLL_DOWN)
	{
		data->zoom -= 0.1;
		data->max_iter -= 1;
	}
	ft_redo(data);
}

void	ft_update_julia(int keycode, t_env *data)
{
	if (keycode == I)
		data->f->c_r += 0.001;
	if (keycode == J)
		data->f->c_i -= 0.001;
	if (keycode == K)
		data->f->c_r -= 0.001;
	if (keycode == L)
		data->f->c_i += 0.001;
	ft_redo(data);
}

void	ft_switch_julia(t_env *data)
{
	if (data->julia_switch == 0)
	{
		data->f->c_r = -0.8;
		data->f->c_i = 0.156;
		data->julia_switch = 1;
	}
	else
	{
		data->f->c_r = 0.285;
		data->f->c_i = 0.01;
		data->julia_switch = 0;
	}
	ft_redo(data);
}

void	ft_reset_julia(t_env *data)
{
	data->f->c_r = 0.285;
	data->f->c_i = 0.01;
	data->julia_switch = 0;
	ft_redo(data);
}

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

int		key_press(int keycode, void *param)
{
	t_env *data;

	data = param;
	if (keycode == ESC)
		exit(0);
	if (keycode == PLUS || keycode == MINUS)
		ft_zoom(keycode, data);
	if (keycode == DOWN || keycode == UP ||
		keycode == LEFT || keycode == RIGHT)
		ft_move(keycode, data);
	if (keycode == ITER_PLUS || keycode == ITER_MINUS)
		ft_max_iter(keycode, data);
	if ((keycode == I || keycode == J || keycode == K || keycode == L) && data->select == JULIA)
		ft_update_julia(keycode, data);
	if (keycode == TAB && data->select == JULIA)
		ft_switch_julia(data);
	if (keycode == R && data->select == JULIA)
		ft_reset_julia(data);
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

int		exit_hook(void)
{
	exit(0);
	return (0);
}
