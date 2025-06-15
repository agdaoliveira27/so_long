NAME = so_long

SRCS = src/main.c src/init.c src/input.c src/map.c src/graphics.c src/game.c src/show_message.c src/validate_map.c src/render_utils.c src/flood_fill.c
OBJS = $(SRCS:.c=.o)
INCL = -I./include -I./lib/libft -I./lib/MLX42/include -I./src
HEADER = ./include/so_long.h
MLX_PATH = lib/MLX42/build
MLX = -L$(MLX_PATH) -lmlx42 -ldl -lglfw -lX11 -lXrandr -lXi -lXxf86vm -lm

CC = cc
CFLAGS = -Wall -Wextra -Werror 

LIBFT_DIR    = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: libft $(NAME)

$(NAME): $(OBJS) ${HEADER} $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) $(LIBFT)

%.o: %.c ${HEADER} $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	make -C $(LIBFT_DIR) --no-print-directory

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR) --no-print-directory

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR) --no-print-directory

re: fclean all

.PHONY: all clean fclean re libft
