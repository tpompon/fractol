/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:25:03 by tpompon           #+#    #+#             */
/*   Updated: 2018/11/16 17:03:50 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cwords(char const *s, char c)
{
	int i;
	int nwords;
	int inword;

	i = 0;
	nwords = 0;
	inword = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			inword = 0;
		else if (inword == 0)
		{
			inword = 1;
			nwords++;
		}
		i++;
	}
	return (nwords);
}

static int		ft_cchars(char const *s, char c, int i)
{
	int nchars;

	nchars = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		nchars++;
	}
	return (nchars);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_cwords(s, c) + 1))))
		return (NULL);
	while (i < ft_cwords(s, c))
	{
		k = 0;
		while (s[j] == c)
			j++;
		if (!(tab[i] = (char *)malloc(sizeof(char) * (ft_cchars(s, c, j) + 1))))
			return (NULL);
		while (s[j] != c && s[j] != '\0')
			tab[i][k++] = s[j++];
		tab[i][k] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
