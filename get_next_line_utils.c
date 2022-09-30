/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 06:53:05 by coder             #+#    #+#             */
/*   Updated: 2022/09/30 07:12:36 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
/*
char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	dest = malloc(((s1_len + s2_len) * sizeof(char)) + 1);
	if (dest)
	{
		gnl_strlcpy(dest, s1, s1_len + 1);
		gnl_strlcat(dest, s2, s1_len + s1_len + 1);
		return (dest);
	}
	return (NULL);
}
*/
