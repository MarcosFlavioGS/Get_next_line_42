/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:05:19 by mflavio-          #+#    #+#             */
/*   Updated: 2022/09/30 06:21:14 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd)
{
	char	*buffer;

	buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}

char	*get_next_line(int fd)
{
  //static char 	extra;
  //char	*line;

  if (!fd || BUFFER_SIZE <= 0)
	  return (NULL);
  return (read_line(fd));
}
