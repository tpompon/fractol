/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:16:50 by tpompon           #+#    #+#             */
/*   Updated: 2019/05/14 14:29:33 by tpompon          ###   ########.fr       */
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

# define WIN_WIDTH 800
# define WIN_HEIGHT 800

# define MAX_ITER_DEFAULT 100

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

# define LEFT_CLICK 1

# define PLUS 69
# define MINUS 78

# define ITER_PLUS 47
# define ITER_MINUS 43

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

# define I 34
# define J 38
# define K 40
# define L 37

# define R 15

# define TAB 48

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define TRICORN 4
# define CLOVER 5

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
	int				julia_switch;
	int				julia_mouse;
	t_fract			*f;
	char			*name;
	void			*img_ptr;
	unsigned int	*img_str;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_env;

void	mandelbrot(t_env *data);
void	julia(t_env *data);
void	burning_ship(t_env *data);
void	tricorn(t_env *data);
void	clover(t_env *data);

int		hexcolor(int r, int g, int b);
void	ft_fill_pixel(int x, int y, int color, t_env *data);
void	ft_display(t_env *data);

int		mouse_move(int x, int y, void *param);
int		mouse_press(int button, int x, int y, void *param);
int		key_press(int keycode, void *param);
int		exit_hook(void);

void	ft_perror(void);

#endif
