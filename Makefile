# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 12:16:50 by mgonzaga          #+#    #+#              #
#    Updated: 2023/11/08 14:58:49 by mgonzaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minitalk

CLIENT = client

SERVER = server

FILES_CLIENT = client.c

FILES_SERVER = server.c ft_printf.c printf_functions.c printf_functions_2.c

OBJ_CLIENT = $(FILES_CLIENT:%.c=%.o)

OBJ_SERVER = $(FILES_SERVER:%.c=%.o)


all: $(NAME)

%.o: %.c
		cc -g3 -Wall -Wextra -Werror  -c $< -o $@ 

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
		cc -Wall -Wextra -Werror $(OBJ_CLIENT) -o $@

$(SERVER): $(OBJ_SERVER)
		cc -Wall -Wextra -Werror $(OBJ_SERVER) -o $@

fclean: clean
		rm -f $(CLIENT) $(SERVER)
clean:
		rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
re: fclean all

.PHONY: all fclean clean re

