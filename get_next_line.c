/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:05:19 by mflavio-          #+#    #+#             */
/*   Updated: 2022/10/04 02:27:58 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void read_line(int fd, char **buffer, char **stattic)
{
	int	r;

	r = 1;
	while (r > 0)
	{
		r = read(fd, *buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(*buffer);
			break ;
		}
		*stattic = gnl_strjoin(*stattic, *buffer);
		if (gnl_strchr(*stattic, '\0'))
			break ;
	}
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stattic;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer)
		return (NULL);
	read_line(fd, &buffer, &stattic);
	return (buffer);
}
