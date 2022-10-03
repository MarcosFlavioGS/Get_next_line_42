/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:05:19 by mflavio-          #+#    #+#             */
/*   Updated: 2022/10/04 00:43:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void read_line(int fd, char **line)
{
	char *buffer;
	int	reader;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	reader = 1;
	/*while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = gnl_strjoin(line, buffer);
		if (gnl_strchr(line, '\n'))
			break ;
	}
	free(buffer);*/
	reader = read(fd, buffer, BUFFER_SIZE);
	buffer[reader] = '\0';
	*line = gnl_strjoin(*line, buffer);
}

char	*get_next_line(int fd)
{
	char	*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line(fd, &line);
	return (line);
}
