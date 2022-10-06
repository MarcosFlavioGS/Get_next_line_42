/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:05:19 by mflavio-          #+#    #+#             */
/*   Updated: 2022/10/06 02:29:28 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_line(int fd, char **str)
{
	char	*buffer;
	char	*tmp;
	int		r;

	r = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	tmp = buffer;
	while (r)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		buffer[r] = '\0';
		tmp = gnl_strdup(buffer);
		*str = gnl_strjoin(tmp, buffer);
		if (gnl_strchr(*str, '\n'))
			break ;
	}
	free(buffer);
	free(tmp);
}

char	*get_next_line(int fd)
{
	static char *str;
	//char		*line;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
		return (NULL);
	read_line(fd, &str);
	return (str);
}
