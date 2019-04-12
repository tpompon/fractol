/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:16:41 by tpompon           #+#    #+#             */
/*   Updated: 2019/04/12 17:24:56 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init_img(t_env *data)
{
	int bpp;
	int s_l;
	int endian;

	data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->img_str = (unsigned int*)mlx_get_data_addr(data->img_ptr, &(bpp), &(s_l), &(endian));
}

static void		ft_init_mlx(t_env *data)
{
	data->mlx_ptr = mlx_init(0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, data->name);
}

void	ft_error(char *error)
{
	ft_putendl(error);
	exit(0);
}

void			ft_perror(void)
{
	perror("\033[0;31mError\033[0m ");
	exit(1);
}

int		ft_is_available(char *str)
{
	if (ft_strcmp(str, "Julia") == 0 || ft_strcmp(str, "Mandelbrot") == 0)
		return (SUCCESS);
	return (ERROR);
}

void	ft_init_env(char *fractal, t_env *data)
{
	data->name = fractal;
	ft_init_mlx(data);
	ft_init_img(data);
}

int		main(int argc, char *argv[])
{
	t_env *data;

	if (argc != 2 || ft_is_available(argv[1]) == ERROR)
		ft_error("\nUsage: ./fractol [map]\n\nMaps available:\n- Julia\n- Mandelbrot\n");
	if (!(data = malloc(sizeof(t_env))))
		ft_perror();
	ft_init_env(argv[1], data);
	ft_display(argv[1], data);
	return (0);
}
