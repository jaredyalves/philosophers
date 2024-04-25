# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 10:45:12 by jcapistr          #+#    #+#              #
#    Updated: 2024/04/25 10:45:34 by jcapistr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread
INCLUDE = -I.

NAME = philo
SRCS = philo.c check.c init.c thread.c action.c monitor.c time.c util.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ 

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug: CFLAGS += -g -fsanitize=thread
debug: re

# vim: ts=4 sts=4 sw=4 noet
