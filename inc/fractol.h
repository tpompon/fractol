/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:16:50 by tpompon           #+#    #+#             */
/*   Updated: 2019/05/10 12:24:36 by tpompon          ###   ########.fr       */
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

# define WIN_WIDTH 1200
# define WIN_HEIGHT 1000

# define MAX_ITER_DEFAULT 250

# define SUCCESS 1
# define ERROR -1

# define BLACK 0x000000
# define WHITE 0xffffff
// # define RED 0xff0000
// # define GREEN 0x00ff00
// # define BLUE 0x0000ff

# define ESC 53
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define PLUS 69
# define MINUS 78

# define ITER_PLUS 47
# define ITER_MINUS 43

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

typedef struct		s_fract
{
	int		x;
	int		y;
	int		iter;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
}					t_fract;

typedef struct		s_env
{
	int				max_iter;
	double			move_x;
	double			move_y;
	double			zoom;
	int				select;
	t_fract			*mandelbrot;
	t_fract			*julia;
	t_fract			*burning_ship;
	char			*name;
	void			*img_ptr;
	unsigned int	*img_str;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_env;

void	mandelbrot(t_env *data);
void	julia(t_env *data);
void	burning_ship(t_env *data);

int		hexcolor(int r, int g, int b);
void	ft_fill_pixel(int x, int y, int color, t_env *data);
void	ft_fill_img_black(t_env *data);
void	ft_display(t_env *data);

int		mouse_press(int button, int x, int y, void *param);
int		key_press(int keycode, void *param);
int		exit_hook(void);

void	ft_perror(void);

#endif
