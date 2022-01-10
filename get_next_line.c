/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarvalh <tcarvalh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:34:40 by tcarvalh          #+#    #+#             */
/*   Updated: 2022/01/10 01:43:08 by tcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*read_until_nl(int fd, char *get_str)
{
	char	*buf;
	ssize_t	size;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	size = BUFFER_SIZE;
	while (!ft_strchr(buf, '\n') && size == BUFFER_SIZE)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[size] = '\0';
		get_str = ft_strjoin(get_str, buf);
	}
	free(buf);
	return (get_str);
}

static char	*save_remainder(char *get_str)
{
	char	*remainder;
	size_t	pos;
	size_t	len;

	len = ft_strlen(get_str);
	pos = ft_strlen(ft_strchr(get_str, '\n'));
	remainder = (char *)malloc(sizeof(char) * (len - pos + 1));
	if(!remainder)
		return (NULL);
	remainder = &get_str[len - pos];
	return (remainder); 
}

char	*get_next_line(int fd)
{
	static char	*prev_read = NULL;
	char		*get_str;
	char		*line;

	if(!prev_read)
		get_str = ft_strdup("");
	else
		get_str = ft_strdup(prev_read);
	printf("get |%s|\n", get_str);
	get_str = read_until_nl(fd, get_str); 
	if (!get_str)
		return (NULL);
	printf("vou printar\n");	
	printf("get |%s|\n", get_str);

	prev_read = save_remainder(get_str);
	printf("prev |%s|\n", prev_read);

	line = ft_strdup("Nao implementei");
	return (line);
}
