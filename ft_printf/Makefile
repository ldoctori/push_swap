LIBFT = ./libft/libft.a

NAME = libftprintf.a

SOURCE_FILES = ft_printf.c ft_flag_conv_split.c ft_c.c ft_func_arr.c ft_s.c ft_id.c \
			   ft_u.c ft_percent.c ft_x.c ft_x_up.c ft_p.c ft_isflag.c ft_flag_minus.c \
			   ft_flag_zero.c

HEADER = ft_printf.h

FLAGS = -c -Wall -Wextra -Werror

all: ${NAME}

$(NAME): ${SOURCE_FILES} ${HEADER}
	$(MAKE) -C ./libft
	cp ./libft/libft.a ./$(NAME)
	gcc $(FLAGS) $(SOURCE_FILES)
	ar rc $(NAME) $(SRC_DIR)*.o
	ranlib $(NAME)

clean:
	rm -f *.o ./libft/*.o

fclean: clean
	rm -f $(NAME) ${LIBFT}

re: fclean all

bonus: re

.PHONY:	all clean fclean re bonus
