# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 04:53:01 by coder             #+#    #+#              #
#    Updated: 2022/10/08 04:04:47 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c 		\
	  get_next_line_utils.c \
	  main.c

all:
	@cc -Wall -Wextra -Werror -D BUFFER_SIZE=50 $(SRC)

exe: all
	@./a.out
