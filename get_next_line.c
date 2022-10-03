/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:05:19 by mflavio-          #+#    #+#             */
/*   Updated: 2022/10/04 01:44:43 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void read_line(int fd, char **buffer)
{
	int	r;

	r = read(fd, *buffer, BUFFER_SIZE);
	*buffer[r] = '\0';
}

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer)
		return (NULL);
	read_line(fd, &buffer);
	return (buffer);
}
