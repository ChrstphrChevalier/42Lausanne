SRCS =	ft_printf.c \
	ft_conv_hexmaj.c \
	ft_conv_hexmin.c \
	ft_conv_adress.c \
	ft_putnbr.c \
	ft_putunbr.c \
	ft_print_c.c \
	ft_print_d.c \
	ft_print_p.c \
	ft_print_s.c \
	ft_print_u.c \
	ft_print_xmaj.c \
	ft_print_xmin.c

OBJS =	${SRCS:.c=.o}

HEAD = ft_printf.h

NAME =	libftprintf.a

CFLAGS =	-Wall -Werror -Wextra

all:	${NAME}

.c.o:
	gcc ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar -rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re