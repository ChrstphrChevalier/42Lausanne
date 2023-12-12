SRCS =	args_analyze.c \
	from_two_to_five.c \
	split.c \
	utils.c \
	push_swap.c \
	push.c \
	radix_sort.c \
	reverse_rotate.c \
	rotate.c \
	swap.c 

OBJS =	${SRCS:.c=.o}

HEAD = push_swap.h

NAME = push_swap

CFLAGS =	-Wall -Werror -Wextra

all:	${NAME}

${NAME}:	${OBJS}
	gcc ${CFLAGS} -I ${HEAD} ${OBJS} -o ${NAME}

.c.o:
	gcc ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re

