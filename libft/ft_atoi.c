/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:34:53 by tpompon           #+#    #+#             */
/*   Updated: 2018/11/13 14:21:21 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int res;
	int sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] != '-' && str[i] != '+' && ft_isdigit(str[i]) == 0)
		return (0);
	if (str[i] == '-')
		sign = -1;
	if (ft_isdigit(str[i]) == 0)
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
