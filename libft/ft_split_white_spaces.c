/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_white_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:42:31 by tpompon           #+#    #+#             */
/*   Updated: 2019/03/24 18:24:15 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_chars(char *str)
{
	int i;

	i = 0;
	while (SP(str[i]) && str[i] != '\0')
		str++;
	while (!(SP(str[i])) && str[i] != '\0')
		i++;
	return (i);
}

int		ft_count_words(char *str)
{
	int i;
	int nbwords;

	i = 0;
	nbwords = 0;
	while (str[i] != '\0')
	{
		while (SP(str[i]) && str[i] != '\0')
			i++;
		while (!(SP(str[i])) && str[i] != '\0')
			i++;
		while (SP(str[i]) && str[i] != '\0')
			i++;
		nbwords++;
	}
	return (nbwords);
}

char	**ft_split_white_spaces(char *str)
{
	int		nbwords;
	int		i;
	int		i2;
	char	**words;
	char	*word;

	i = 0;
	i2 = 0;
	nbwords = ft_count_words(str);
	words = malloc(sizeof(char*) * (nbwords + 1));
	while (i2 < nbwords)
	{
		word = (char*)malloc(sizeof(char) * (ft_count_chars(str) + 1));
		if (!word)
			return (NULL);
		while (SP(str[0]) && str[0] != '\0')
			str++;
		while (!(SP(str[0])) && str[0] != '\0')
			word[i++] = *str++;
		word[i] = '\0';
		words[i2++] = word;
		i = 0;
	}
	words[nbwords] = 0;
	return (words);
}
