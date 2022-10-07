/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:47:27 by coder             #+#    #+#             */
/*   Updated: 2022/10/08 00:54:27 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int 	fd;
	char	*result = malloc(30);
	//int   numbofchars;
	fd = open("teste.txt", O_RDONLY);
	while (result != NULL)
	{
		result = get_next_line(fd);
		printf("%s", result);
	}
	close(fd);
	return (0);
 }
