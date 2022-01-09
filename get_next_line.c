/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarvalh <tcarvalh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:34:40 by tcarvalh          #+#    #+#             */
/*   Updated: 2022/01/09 21:07:36 by tcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*read_until_nl(int fd, char *get_str)
{
	char	*buf;
	ssize_t	size;

	printf("malloc\n");
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	size = BUFFER_SIZE;
	printf("while\n");
	while (!ft_strchr(buf, '\n') && size == BUFFER_SIZE)
	{
		printf("read\n");
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
		{
			free(buf);
			return (NULL);
		}
		printf("fnlzd str\n");
		buf[size] = '\0';
		printf("join\n");
		get_str = ft_strjoin(get_str, buf);
	}
	printf("free\n");
	free(buf);
	printf("return\n");
	return (get_str);
}

char	*get_next_line(int fd)
{
	static char	*prev_read = NULL;
	char		*get_str;
	char		*line;

	printf("criando getstr\n");
	if(!prev_read)
		get_str = ft_strdup("");
	else
		get_str = ft_strdup(prev_read);
	printf("lendo\n");
	if (!read_until_nl(fd, get_str))
		return (NULL);
	printf("vou printar\n");	
	printf("|%s|\n", get_str);

	line = ft_strdup("Nao implementei");
	return (line);
}
