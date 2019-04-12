/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 21:00:27 by tpompon           #+#    #+#             */
/*   Updated: 2018/11/16 17:02:52 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_itoc_len(long n)
{
	int		size;

	size = 1;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*str;

	nb = n;
	i = ft_itoc_len(nb);
	nb = nb < 0 ? -nb : nb;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
