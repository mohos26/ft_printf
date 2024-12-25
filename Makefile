SRCS = ft_memcpy.c ft_puthex.c ft_putstr.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putptr.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $?

%.o: %.c ft_printf.h
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
