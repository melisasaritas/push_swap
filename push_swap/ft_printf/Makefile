# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:13:18 by msaritas          #+#    #+#              #
#    Updated: 2022/10/22 15:01:18 by msaritas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS            = ft_printc.c ft_printcapitalx.c ft_printf.c ft_printi.c \
				ft_printp.c ft_prints.c ft_printu.c ft_printx.c

OBJS            = $(SRCS:.c=.o)
CC              = gcc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror -I.
NAME            = libftprintf.a
all:            $(NAME)
$(NAME):        $(OBJS)
				ar rcs $(NAME) $(OBJS)
clean:
				$(RM) $(OBJS)
fclean:         clean
				$(RM) $(NAME)
re:             fclean $(NAME)
.PHONY:         all clean fclean re bonus
