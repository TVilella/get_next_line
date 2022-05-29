/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarvalh <tcarvalh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:34:40 by tcarvalh          #+#    #+#             */
/*   Updated: 2022/05/29 21:14:09 by tcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*read_until_nl(int fd, char *str)
{
	char	*buf;
	char	*tmp;
	ssize_t	size;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	size = BUFFER_SIZE;
	while (!ft_strchr(str, '\n') && size == BUFFER_SIZE)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[size] = '\0';
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	free(buf);
	return (str);
}

static char	*save_remainder(char *str)
{
	char	*remainder;
	size_t	len;
	size_t	index;

	index = 0;
	len = ft_strlen(str);
	while (str[index] != '\0' && str[index] != '\n')
		index++;
	if (!str[index])
		return (NULL);
	remainder = (char *)malloc(sizeof (char) * (len - index + 1));
	if (!remainder)
		return (NULL);
	ft_strlcpy(remainder, str + index + 1, len - index + 1);
	return (remainder);
}

static char	*extract_line(char *str)
{
	char	*line;
	size_t	pos;
	size_t	len;

	len = ft_strlen(str);
	pos = len - ft_strlen(ft_strchr(str, '\n'));
	line = (char *)malloc(sizeof(char) * (pos + 1));
	ft_strlcpy(line, str, pos + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*prev_str = NULL;
	char		*str;
	char		*line;

	line = NULL;
	if( fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!prev_str)
		str = ft_strdup("");
	else
		str = ft_strdup(prev_str);
	str = read_until_nl(fd, str);
	if (!str)
		return (NULL);
	prev_str = save_remainder(str);
	if (prev_str == NULL)
	{
		free(prev_str);
		return (str);
	}
	line = extract_line(str);
	free(str);
	return (line);
}
