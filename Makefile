NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS := ft_putnbr_fd.c ft_printf.c ft_putpointer_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_put_lowerhexa_fd.c ft_putunsignednbr_fd.c

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