# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 10:06:20 by mmehran           #+#    #+#              #
#    Updated: 2021/04/21 10:08:08 by mmehran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

OBJS = ft_printutils.o ft_printparse.o ft_printchars.o ft_printnumbers_precision.o ft_printnumbers.o ft_printf.o

$(NAME): $(OBJS)
	make -C ./Libft
	cp ./Libft/libft.a ${NAME}
	$(AR) $@ $^

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

clean:
	make clean -C ./Libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C ./Libft
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
