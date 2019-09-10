/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:50:32 by tpompon           #+#    #+#             */
/*   Updated: 2019/09/10 16:53:31 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	ft_max_iter(int keycode, t_env *data)
{
	if (keycode == ITER_PLUS && data->max_iter < 499)
		data->max_iter += 10;
	if (keycode == ITER_MINUS && data->max_iter > 1)
		data->max_iter -= 10;
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
	if ((keycode == I || keycode == J || keycode == K || keycode == L)
		&& data->select == JULIA)
		ft_update_julia(keycode, data);
	if (keycode == TAB && data->select == JULIA)
		ft_switch_julia(data);
	if (keycode == R && data->select == JULIA)
		ft_reset_julia(data);
	return (0);
}
