SRC = operations1.c push_swap.c operations2.c operations3.c operations4.c \
		put_stack_b.c do_LIS.c put_stack_a.c put_stack_a_helper.c util.c \
		check.c util2.c
SRC_BNS = checker_bonus.c checker_1_bonus.c checker_2_bonus.c checker_3_bonus.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c checker_4_bonus.c
OBJS = $(SRC:.c=.o)
BNS_OBJS = $(SRC_BNS:.c=.o)
NAME = push_swap
NAME_BNS = checker
CC = gcc
FLAGS = -Wall -Wextra -Werror -I include

PRINTF = cd ft_printf && make
LIB1 = ft_printf/libftprintf.a

LIBFT = cd libft && make
LIB2 = libft/libft.a

all: ft_printf libft $(NAME)
bonus: ft_printf libft $(NAME_BNS)

libft:		
				@$(LIBFT)
ft_printf:		
				@$(PRINTF)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIB1) $(LIB2) -o $(NAME)
$(NAME_BNS): $(BNS_OBJS)
	@$(CC) $(FLAGS) $(BNS_OBJS) $(LIB1) $(LIB2) -o $(NAME_BNS)

clean:
				$(RM) $(OBJS)
				$(RM) $(BNS_OBJS)
				@cd libft && make clean
				@cd ft_printf && make clean
fclean:         clean
				$(RM) $(NAME)
				$(RM) $(NAME_BNS)
				@cd ft_printf && make fclean
				@cd libft && make fclean  
re:             fclean all
.PHONY:         all libft ft_printf clean fclean re
