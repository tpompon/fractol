/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 20:21:57 by tpompon           #+#    #+#             */
/*   Updated: 2018/11/16 13:49:23 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j > 0)
		j--;
	if (j == 0)
		return (ft_strnew(0));
	len = j - i + 1;
	str = ft_strsub(s, i, len);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	return (str);
}
