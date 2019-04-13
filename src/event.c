/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:26:18 by tpompon           #+#    #+#             */
/*   Updated: 2019/04/13 21:25:24 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_redo(t_env *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_fill_img_black(data);
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
		data->zoom += 0.1;
	if (keycode == MINUS || keycode == SCROLL_DOWN)
		data->zoom -= 0.1;
	ft_redo(data);
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
	return (0);
}

int		exit_hook(void)
{
	exit(0);
	return (0);
}
