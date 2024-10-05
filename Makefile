NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS := ft_putnbr_fd.c ft_printf.c ft_putpointer.c ft_putstr.c ft_putchar.c ft_put_hexa_fd.c ft_putunsignednbr_fd.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re