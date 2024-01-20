# Makefile for the Philosopher project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Header files directory
HEADER = philosopher.h

# Source files and object files for Philosopher project
SRC = init.c philosopher.c routine_utils.c routine.c utils.c
OBJ = $(SRC:.c=.o)

# Name of the final executable
NAME = philosopher

# Rule for making the final executable
$(NAME): $(OBJ) Printf/libftprintf.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -LPrintf -lftprintf

# Rule for making object files for Philosopher project
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for cleaning object files
clean:
	rm -f $(OBJ)

# Rule for cleaning the executable
fclean: clean
	rm -f $(NAME)

# Rule for re-making everything
re: fclean all

.PHONY: all clean fclean re

