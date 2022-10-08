/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:47:27 by coder             #+#    #+#             */
/*   Updated: 2022/10/08 04:06:34 by coder            ###   ########.fr       */
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
	fd = open("A_Poison_Tree_William_Blake.txt", O_RDONLY);
	result = get_next_line(fd);
	for(int i = 0; i < 5 && result != NULL; i++)
	{
		printf("%s", result);
		result = get_next_line(fd);
	}
	close(fd);
	return (0);
 }
