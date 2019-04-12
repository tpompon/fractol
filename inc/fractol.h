/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:16:50 by tpompon           #+#    #+#             */
/*   Updated: 2019/04/12 18:02:25 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <../libft/libft.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define MAX_ITER 200

# define SUCCESS 1
# define ERROR -1

# define ESC 53

typedef struct		s_env
{
	char			*name;
	void			*img_ptr;
	unsigned int	*img_str;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_env;

void	mandelbrot(t_env *data);
void	julia(t_env *data);

int		hexcolor(int r, int g, int b);
void	ft_fill_pixel(int x, int y, int color, t_env *data);
void	ft_display(char *fractal, t_env *data);

int		key_press(int keycode, void *param);
int		exit_hook(void);

#endif
