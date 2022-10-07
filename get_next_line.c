/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:05:19 by mflavio-          #+#    #+#             */
/*   Updated: 2022/10/07 04:09:21 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

static char	*gnl_strdup(const char *s)
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

static void	read_line(int fd, char **str)
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
	printf("@str depois do read: %s@\n", *str);
	free(buffer);
	free(tmp);
}

static char	*get_line(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc(gnl_strlen(str));
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

static void	clean_s(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)malloc(gnl_strlen(str) + 1);
	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i])
	{
		tmp[j++] = str[i++];
	}
	tmp[j] = '\0';
	printf("$string tmp: %s$\n", tmp);
	str = gnl_strdup(tmp);
	printf("#str depois do strdup: %s#\n", str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
		return (NULL);
	read_line(fd, &str);
	line = get_line(str);
	clean_s(str);
	if (gnl_strchr(line, '\0') && gnl_strchr(line, '\n') == 0)
		free(str);
	return (line);
}
