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

LIB		= ar rcs
RM		= rm -f
CC		= gcc
CCFLAGS	= -Wextra -Werror -Wall
NAME	= minitalk.a
SRC		= cient.c server.c

OBJ = $(SRC:.c=.o)
INCLUDE = minitalk.h

all : $(NAME)
$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all
