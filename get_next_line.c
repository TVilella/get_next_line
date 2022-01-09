/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarvalh <tcarvalh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:34:40 by tcarvalh          #+#    #+#             */
/*   Updated: 2022/01/09 05:54:49 by tcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*prev_read;
	char		*get_buf;
	char		*line;
	ssize_t		qtd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	get_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!get_buf)
		return (NULL);
		
	qtd = read(fd, get_buf, BUFFER_SIZE);
	if (qtd < BUFFER_SIZE)
		return (NULL);


	line = get_buf;

	return (line);
}
