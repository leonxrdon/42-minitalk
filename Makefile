# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 13:24:40 by lnarvaez          #+#    #+#              #
#    Updated: 2023/06/05 13:24:43 by lnarvaez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM		= rm -f
CC		= gcc
CCFLAGS	= -Wextra -Werror -Wall
NAME	= client server
SRC		= client.c server.c

all: $(NAME)

client: client.c
	$(CC) $(CCFLAGS) -o client client.c

server: server.c
	$(CC) $(CCFLAGS) -o server server.c

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
