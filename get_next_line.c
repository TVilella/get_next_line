/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarvalh <tcarvalh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:34:40 by tcarvalh          #+#    #+#             */
/*   Updated: 2022/05/30 15:34:27 by tcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*read_until_nl(int fd, char *str)
{
	ssize_t		size;
	char		*tmp;
	char		*buffer;
	int			nl;

	size = BUFFER_SIZE;
	nl = 0;
	buffer = (char *)malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!nl && size == BUFFER_SIZE)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		if (!str)
			str = ft_strdup("");
		tmp = str;
		str = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(str, '\n'))
			nl = 1;
	}
	free(buffer);
	return (str);
}

static char	*save_remainder(char *str)
{
	int		index;
	char	*remainder;
	size_t	len;

	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (str[index] == '\0')
	{
		free(str);
		return (NULL);
	}
	len = ft_strlen(str);
	remainder = (char *)malloc(sizeof (char) * len - index + 1);
	if (!remainder)
		return (NULL);
	ft_strlcpy(remainder, str + index + 1, len - index + 1);
	free(str);
	return (remainder);
}

static char	*extract_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof (char) * (i + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, str, i + 2);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_until_nl(fd, str);
	if (!str)
		return (NULL);
	line = extract_line(str);
	str = save_remainder(str);
	return (line);
}
