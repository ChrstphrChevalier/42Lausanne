NAME		=	client

NAME2		=	server

SRCS		=	client.c

SRCS2		=	server.c

OBJS		=	$(SRCS:.c=.o)

OBJS2		=	$(SRCS2:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm -f

all			:	$(NAME) $(NAME2)

$(NAME)		:	$(OTHER) $(OBJS)
				make -C libft/
				make -C ft_printf/
				$(CC) $(CFLAGS) -o $(NAME) libft/libft.a ft_printf/libftprintf.a $(OBJS)

$(NAME2)	:	$(OTHER) $(OBJS2)
				make -C libft/
				make -C ft_printf/
				$(CC) $(CFLAGS) -o $(NAME2) libft/libft.a ft_printf/libftprintf.a $(OBJS2)

clean		: 
				$(RM) $(OBJS) $(OBJS2) libft/*.o ft_printf/*.o

fclean		:	clean
				$(RM) $(NAME) $(NAME2) libft/libft.a ft_printf/libftprintf.a

re			:	fclean all

.PHONY		:	all clean fclean re
