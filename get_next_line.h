/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:05:34 by mflavio-          #+#    #+#             */
/*   Updated: 2022/10/08 02:45:15 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *str);
size_t	gnl_strlcpy(char *dest, const char *src, size_t size);
#endif
