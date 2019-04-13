/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:21:21 by tpompon           #+#    #+#             */
/*   Updated: 2019/04/13 21:33:28 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hud(t_env *data)
{
	char *str;
	char *max_iter;

	max_iter = ft_itoa(data->max_iter);
	if (!(str = malloc(sizeof(char) * (ft_strlen(max_iter) + ft_strlen("Iterations: ")) + 1)))
		ft_perror();
	ft_strcpy(str, "Iterations: ");
	ft_strcat(str, max_iter);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, WHITE, str);
	free(max_iter);
	free(str);
}

void	ft_display(t_env *data)
{
	if (data->select == MANDELBROT)
		mandelbrot(data);
	else if (data->select == JULIA)
		julia(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	hud(data);
	mlx_hook(data->win_ptr, 4, 0, mouse_press, data);
	mlx_hook(data->win_ptr, 2, 0, key_press, data);
	mlx_hook(data->win_ptr, 17, 0, exit_hook, data);
	mlx_loop(data->mlx_ptr);
}
