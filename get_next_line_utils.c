/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 06:53:05 by coder             #+#    #+#             */
/*   Updated: 2022/10/06 06:06:34 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

size_t	gnl_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return (gnl_strlen(src));
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (gnl_strlen(src));
}

size_t	gnl_strlcat(char *dest, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;
	size_t	dest_return;

	d_len = gnl_strlen(dest);
	s_len = gnl_strlen(src);
	i = 0;
	if (dst_size > d_len)
	{
		dest_return = d_len + s_len;
		while (src[i] && d_len < dst_size - 1)
		{
			dest[d_len++] = src[i++];
		}
		dest[d_len] = 0;
		return (dest_return);
	}
	else
	{
		return (s_len + dst_size);
	}
}

char	*gnl_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		else
			i++;
	}
	return ((void *) NULL);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		s1_len;
	int		s2_len;

	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	dest = malloc(((s1_len + s2_len) * sizeof(char)) + 1);
	if (dest)
	{
		gnl_strlcpy(dest, s1, s1_len + 1);
		gnl_strlcat(dest, s2, s1_len + s2_len + 1);
		return (dest);
	}
	return (NULL);
}
