/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:26:18 by tpompon           #+#    #+#             */
/*   Updated: 2019/09/10 16:53:13 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_redo(t_env *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_display(data);
}

void	ft_zoom(int keycode, t_env *data)
{
	if (keycode == PLUS || keycode == SCROLL_UP)
	{
		data->zoom += 0.1;
		data->max_iter += 1;
	}
	if ((keycode == MINUS || keycode == SCROLL_DOWN) && data->zoom > 0.2)
	{
		data->zoom -= 0.1;
		data->max_iter -= 1;
	}
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

int		exit_hook(void)
{
	exit(0);
	return (0);
}
