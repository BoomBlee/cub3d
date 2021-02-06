NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -I. -I./minilibx
LIBS = -L./libft -L./minilibx -lft -lm -lmlx -lXext -lX11
SRCS = \
src/file0.c \
src/file1.c \
src/file2.c \
src/file3.c \
src/file4.c \
src/file5.c \
src/file6.c \
src/file7.c \
src/file8.c \
src/file9.c

BINS = $(SRCS:.c=.o)

.PHONY: all clean fclean re bonus libft minilibx

all: $(NAME)

libft:
	@make -C libft

minilibx:
	@make -C minilibx

$(NAME): libft minilibx $(BINS)
	@$(CC) $(CFLAGS) -o $(NAME) $(BINS) $(LIBS)
	@clear
	@echo Cub3D created

%.o: %.c
	@$(CC) $(CFLAGS) -c $(@:.o=.c) -o $@ $(LIBS)

clean:
	@make fclean -C libft
	@make clean -C minilibx
	@rm -f $(BINS)
	@clear
	@echo clean completed

fclean: clean
	@rm -f $(NAME) screen.bmp
	@clear
	@echo fclean completed

re: fclean all