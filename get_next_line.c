/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:05:19 by mflavio-          #+#    #+#             */
/*   Updated: 2022/10/05 03:21:49 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_line(int fd, char **stattic, char **tmp)
{
	char	*buffer;
	int		ret;

	buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	ret = 1;
	while (gnl_strchr(*stattic, '\n') && ret)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return ;
		buffer[ret] = '\0';
		*tmp = gnl_strdup(*stattic);
		*stattic = gnl_strjoin(*tmp, buffer);
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	static char	*stattic;
	char		*line;
	char		*tmp;

	stattic = NULL;
	line = NULL;
	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line(fd, &stattic, &tmp);
	return (stattic);
}
