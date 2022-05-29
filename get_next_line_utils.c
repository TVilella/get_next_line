/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarvalh <tcarvalh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:34:44 by tcarvalh          #+#    #+#             */
/*   Updated: 2022/05/29 20:49:10 by tcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len) != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int		index;
	size_t	length;

	length = ft_strlen(s);
	if (c == 0 && length == 0)
		return ((char *)s);
	index = 0;
	while (*(s + index) != '\0')
	{
		if (*(s + index) == (unsigned char)c)
			return ((char *)(s + index));
		index++;
	}
	if (*(s + index) == (unsigned char)c)
		return ((char *)(s + index));
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s1);
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, len + 1);
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(s1_len + s2_len + 1);
	if (new != NULL)
	{
		ft_strlcpy(new, s1, s1_len + 1);
		ft_strlcpy(new + s1_len, s2, s2_len + 1);
	}
	return (new);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	l_src;
	size_t	index;

	l_src = ft_strlen(src);
	index = 0;
	if (dstsize == 0)
		return (l_src);
	while (index < dstsize - 1 && *(src + index))
	{
		*(dst + index) = *(src + index);
		index++;
	}
	*(dst + index) = '\0';
	return (l_src);
}
