/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:10:35 by tpompon           #+#    #+#             */
/*   Updated: 2019/03/29 16:26:21 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		gnl_read(const int fd, char **str)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;
	int		i;

	ft_bzero(buf, BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		tmp = *str;
		*str = ft_strjoin(*str, buf);
		free(tmp);
		if (ft_strchr(*str, '\n'))
			break ;
		i = 0;
		while (i < BUFF_SIZE)
		{
			if (str[0][i] == '\0')
				return (ERROR);
			i++;
		}
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	return (ret);
}

static char		*gnl_check(char **str)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while (*(*str + i) != '\n' && *(*str + i) != '\0')
		i++;
	line = ft_strsub(*str, 0, i);
	tmp = *str;
	*str = ft_strsub(*str, i + 1, ft_strlen(*str) - i);
	free(tmp);
	return (line);
}

int				ft_get_next_line(const int fd, char **line)
{
	static char		*str;
	int				ret;

	if (fd < 0)
		return (ERROR);
	if (!str)
		if (!(str = ft_strnew(0)))
			return (ERROR);
	if (ft_strchr(str, '\n'))
	{
		if (!(*line = gnl_check(&str)))
			return (ERROR);
	}
	else
	{
		if ((ret = gnl_read(fd, &str)) == END && !*str)
			return (END);
		if (ret == ERROR)
			return (ERROR);
		*line = gnl_check(&str);
	}
	return (SUCCESS);
}
