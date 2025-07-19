NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c functions.c functions_p.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
