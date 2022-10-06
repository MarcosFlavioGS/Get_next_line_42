/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:05:19 by mflavio-          #+#    #+#             */
/*   Updated: 2022/10/06 06:07:21 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strdup(const char *s)
{
	int		s_size;
	int		i;
	char	*dup;

	i = 0;
	if (!s)
		return (gnl_strdup(""));
	s_size = gnl_strlen(s);
	dup = (char *)malloc((s_size + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	read_line(int fd, char **str)
{
	char	*buffer;
	char	*tmp;
	int		r;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	r = 1;
	while (r)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		buffer[r] = '\0';
		tmp = gnl_strdup(*str);
		*str = gnl_strjoin(tmp, buffer);
		if (gnl_strchr(*str, '\n'))
			break ;
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	static char	*str;
	//char		*line;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
		return (NULL);
	read_line(fd, &str);
	return (str);
}
