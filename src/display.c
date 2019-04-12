/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:21:21 by tpompon           #+#    #+#             */
/*   Updated: 2019/04/12 17:59:13 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_display(char *fractal, t_env *data)
{
	if (ft_strcmp(fractal, "Mandelbrot") == 0)
		mandelbrot(data);
	else if (ft_strcmp(fractal, "Julia") == 0)
		julia(data);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_hook(data->win_ptr, 2, 0, key_press, data);
	mlx_hook(data->win_ptr, 17, 0, exit_hook, data);
	mlx_loop(data->win_ptr);
}
