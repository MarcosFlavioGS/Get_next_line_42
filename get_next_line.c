/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:05:19 by mflavio-          #+#    #+#             */
/*   Updated: 2022/10/05 00:39:22 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_line(int fd, char **stattic, char **tmp)
{
	char	*buffer;
	int		ret;


	buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	*tmp = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	*
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return ;
		buffer[ret] = '\0';
		*tmp = gnl_strdup(*stattic);
		free(*stattic);
		*stattic = gnl_strjoin(*tmp, buffer);
		free(*tmp);
		if (gnl_strchr(*stattic, '\n'))
			break ;
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
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line(fd, &stattic, &tmp);
	return (stattic);
}
