# Nom de l'exécutable
NAME = so_long

# Compilateur et drapeaux de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Chemins des dossiers pour les sources, les en-têtes, et les bibliothèques
SRC_DIR = ./
INC_DIR = ./includes/
LIBFT_DIR = Libft/
PRINTF_DIR = Printf/
GNL_DIR = GetNextLine/
MLX_DIR = MLX/

# Bibliothèques
LIBFT = $(LIBFT_DIR)libft.a
PRINTF = $(PRINTF_DIR)libftprintf.a
MLX = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Fichiers sources
SRCS = games.c graphics.c parsing.c so_long.c utils.c \
       $(GNL_DIR)get_next_line.c $(GNL_DIR)get_next_line_utils.c

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Règle par défaut
all: $(NAME)

# Règle pour compiler MLX
$(MLX_DIR):
	make -C $(MLX_DIR)

# Règle pour créer l'exécutable
$(NAME): $(LIBFT) $(PRINTF) $(MLX_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME)

# Règles pour compiler les bibliothèques Libft et Printf
$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

# Règle pour créer les fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(GNL_DIR) -I $(MLX_DIR) -c $< -o $@

# Règles pour nettoyer les fichiers objets et les exécutables
clean:
	rm -f $(SRC_DIR)*.o
	rm -f $(GNL_DIR)*.o
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	make -C $(MLX_DIR) fclean

# Règle pour reconstruire tout
re: fclean all

# Empêche make d'être confus avec un fichier du même nom
.PHONY: all clean fclean re
