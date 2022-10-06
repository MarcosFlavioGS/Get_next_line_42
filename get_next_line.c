/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:05:19 by mflavio-          #+#    #+#             */
/*   Updated: 2022/10/06 05:48:00 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char		*line;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
		return (NULL);
	read_line(fd, &str);
	return (str);
}
