CC = gcc

NAME = push_swap

BONUS_NAME = checker

HEADER = push_swap.h

SOURCE = push_swap.c stack_utils_1.c stack_utils_2.c ft_atoi.c \
			stack_functions.c s_p_commands.c rot_commands.c \
			double_commands.c arr_sorting.c is_sorted_functions.c \
			small_stack_a.c small_stack_b.c join_parse_args.c \
			check_duplicates.c	

BONUS_SOURCE = my_checker.c stack_functions.c s_p_commands.c ft_atoi.c\
				rot_commands.c double_commands.c is_sorted_functions.c \
				stack_utils_1.c stack_utils_2.c get_next_line.c \
				join_parse_args.c check_duplicates.c 
				
OBJ = $(SOURCE:.c=.o)

BONUS_OBJ = $(BONUS_SOURCE:.c=.o)

FLAGS = -Wall -Wextra -Werror

%.o: %.c $(HEADER)
	$(CC) -I -I./ft_printf -I./ft_printf/libft -O3 -c $(FLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./ft_printf
	$(CC) $(OBJ) -Lft_printf -lftprintf -o $(NAME) 

bonus: $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) -Lft_printf -lftprintf -o $(BONUS_NAME) 


clean:
	rm -f *.o ./ft_printf/*.o ./ft_printf/libft/*.o

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) ./ft_printf/libftprintf.a ./ft_printf/libft/libft.a

re: fclean all

