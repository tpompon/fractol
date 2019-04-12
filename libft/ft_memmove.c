/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:45:06 by tpompon           #+#    #+#             */
/*   Updated: 2018/11/15 15:28:06 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while ((int)len > 0)
		{
			len--;
			((char *)dst)[len] = ((char *)src)[len];
		}
	}
	return (dst);
}
