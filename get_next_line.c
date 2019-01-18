/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 04:30:25 by caking            #+#    #+#             */
/*   Updated: 2019/01/15 21:54:08 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static		int		line_reader(char **str, int fd)
{
	int		flag;
	char	*sbuff;
	char	buf[BUFF_SIZE + 1];

	if ((flag = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[flag] = '\0';
	sbuff = *str;
	*str = ft_strjoin(*str, buf);
	if (*sbuff != 0)
		free(sbuff);
	return (flag);
}

static		int		next_line(char **str, char **line, char *s)
{
	int		i;
	char	*sbuff;

	i = 0;
	if (*s == '\n')
		i = 1;
	*s = 0;
	*line = ft_strjoin("", *str);
	if (i == 0 && ft_strlen(*str) != 0)
	{
		*str = ft_strnew(1);
		return (1);
	}
	else if (i == 0 && !(ft_strlen(*str)))
		return (0);
	sbuff = *str;
	*str = ft_strjoin(s + 1, "");
	free(sbuff);
	return (i);
}

int					get_next_line(const int fd, char **line)
{
	int				flag;
	char			*sbuff;
	static char		*str;

	if (str == 0)
		str = "";
	if (!line || BUFF_SIZE < 1)
		return (-1);
	flag = BUFF_SIZE;
	while (line)
	{
		sbuff = str;
		while (*sbuff || flag < BUFF_SIZE)
		{
			if (*sbuff == '\n' || *sbuff == 0 || *sbuff == -1)
				return (next_line(&str, line, sbuff));
			sbuff++;
		}
		flag = line_reader(&str, fd);
		if (flag == -1)
			return (-1);
	}
	return (0);
}
