/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estudando.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 03:33:39 by coder             #+#    #+#             */
/*   Updated: 2022/09/30 04:56:58 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Primeiro preciso aprender como funciona a função read, e estudar seu comportamento*/
#include <fcntl.h>/*open()*/
#include <unistd.h>/*close()*/
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		res;
	char	*buffer;

	buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	fd = open("teste.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	/*Aprender o funcionamento da função read()
	Prototype:
	ssize_t read(int fd, void *buf, size_t count);*/
	res = read(fd, buffer, BUFFER_SIZE);
	close(fd);
	printf("%s\n", buffer);
	printf("%i\n", res);
	return (0);
}
