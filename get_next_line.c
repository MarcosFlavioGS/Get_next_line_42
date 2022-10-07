/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:05:19 by mflavio-          #+#    #+#             */
/*   Updated: 2022/10/08 00:38:18 by coder            ###   ########.fr       */
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
	//printf("@str depois do read: %s@\n", *str);
	free(buffer);
	free(tmp);
}

static char	*get_line(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	i++;
	temp = (char *)malloc(i + 1);
	if (!temp)
	{
		free(temp);
		free(str);
		return (NULL);
	}
	gnl_strlcpy(temp, str, i + 1);
	temp[i] = '\0';
	return (temp);
}

static char	*clean_s(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	i++;
	tmp = (char *)malloc(gnl_strlen(str) - i + 1);
	while (str[i])
	{
		tmp[j++] = str[i++];
	}
	tmp[j] = '\0';
	//printf("$string tmp: %s$\n", tmp);
	str = gnl_strdup(tmp);
	//printf("#str depois do strdup: %s#\n", str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
		return (NULL);
	read_line(fd, &str);
	line = get_line(str);
	str = clean_s(str);
	return (line);
}
