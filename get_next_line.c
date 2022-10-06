/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:05:19 by mflavio-          #+#    #+#             */
/*   Updated: 2022/10/06 23:51:24 by coder            ###   ########.fr       */
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
	r = read(fd, buffer, BUFFER_SIZE);
	while (r)
	{
		buffer[r] = '\0';
		tmp = gnl_strdup(*str);
		*str = gnl_strjoin(tmp, buffer);
		if (gnl_strchr(*str, '\n'))
			break ;
		r = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	free(tmp);
}

char	*get_line(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc(11);
	if (!temp)
	{
		free(temp);
		free(str);
		return (NULL);
	}
	while (str[i])
	{
		if (str[i] == '\n')
		{
			temp[i++] = '\n';
			break ;
		}
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	str = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
		return (NULL);
	read_line(fd, &str);
	line = get_line(str);
	return (line);
}
