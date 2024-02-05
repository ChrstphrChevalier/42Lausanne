# Makefile for the Philosopher project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Header files directory
HEADER = philosopher.h

# Source files and object files for Philosopher project
SRC = init.c philosopher.c ft_usleep.c routine_utils.c routine.c routine_supervisor.c threads.c utils.c data_race.c
OBJ = $(SRC:.c=.o)

# Name of the final executable
NAME = philo

all: $(NAME)

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

