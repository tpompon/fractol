/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:16:41 by tpompon           #+#    #+#             */
/*   Updated: 2019/09/10 17:01:23 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init_img(t_env *data)
{
	int bpp;
	int s_l;
	int endian;

	if (data->select == MANDELBROT)
	{
		data->f->c_r = 0.285;
		data->f->c_i = 0.01;
	}
	if (!(data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		ft_perror();
	if (!(data->img_str = (unsigned int*)mlx_get_data_addr(data->img_ptr,
		&(bpp), &(s_l), &(endian))))
		ft_perror();
}

static void		ft_init_mlx(t_env *data)
{
	if (!(data->mlx_ptr = mlx_init(0)))
		ft_perror();
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
		data->name)))
		ft_perror();
}

int				ft_is_available(char *str)
{
	if (ft_strcmp(str, "Julia") == 0 || ft_strcmp(str, "Mandelbrot") == 0
		|| ft_strcmp(str, "Burning_ship") == 0
		|| ft_strcmp(str, "Tricorn") == 0
		|| ft_strcmp(str, "Clover") == 0)
		return (SUCCESS);
	return (ERROR);
}

int				ft_init_env(char *fract, t_env *data)
{
	data->max_iter = MAX_ITER_DEFAULT;
	data->zoom = 1.0;
	data->move_x = 0.0;
	data->move_y = 0.0;
	data->name = fract;
	data->select = 0;
	data->julia_switch = 0;
	data->julia_mouse = 0;
	if (!(data->f = malloc(sizeof(t_fract))))
		return (-1);
	if (ft_strcmp(data->name, "Mandelbrot") == 0)
		data->select = MANDELBROT;
	else if (ft_strcmp(data->name, "Julia") == 0)
		data->select = JULIA;
	else if (ft_strcmp(data->name, "Burning_ship") == 0)
		data->select = BURNING_SHIP;
	else if (ft_strcmp(data->name, "Tricorn") == 0)
		data->select = TRICORN;
	else if (ft_strcmp(data->name, "Clover") == 0)
		data->select = CLOVER;
	ft_init_mlx(data);
	ft_init_img(data);
	return (0);
}

int				main(int argc, char *argv[])
{
	t_env	*data;
	char	*fract;

	if (argc >= 2)
	{
		fract = argv[1];
		format_name(fract);
		if (ft_is_available(fract) == ERROR)
			ft_usage();
		if (!(data = malloc(sizeof(t_env))))
			ft_perror();
		if (ft_init_env(fract, data) == -1)
			return (-1);
		ft_display(data);
		free(data);
	}
	else
	{
		ft_usage();
	}
	return (0);
}
