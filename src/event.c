/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:26:18 by tpompon           #+#    #+#             */
/*   Updated: 2019/03/31 13:27:17 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press(int keycode, void *param)
{
	t_env *fdf;

	fdf = param;
	if (keycode == ESC)
		exit(0);
	return (0);
}

int		exit_hook(void)
{
	exit(0);
	return (0);
}
