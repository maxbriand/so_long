NAME = so_long
CC = cc
#FLAGS = -Wall -Werror -Wextra
SRC_DIR = ./src
LIBFT = libft/libft.a
MLX = -lmlx -lX11 -lXext

PARSING = src/parsing/
HOOK = src/hook/
MAP = src/map/
WINDOW = src/window/
GAME = src/game/

SRC = 	src/main.c \
		src/exit.c \
		\
		$(PARSING)ft_parsing.c \
		$(PARSING)ft_parsing_map_extension.c \
		$(PARSING)ft_parsing_map_components.c \
		$(PARSING)ft_parsing_map_rectangular.c \
		$(PARSING)ft_parsing_map_closed.c \
		$(PARSING)ft_parsing_map_path.c \
		$(PARSING)ft_invalid_map_exit.c \
		$(PARSING)ft_ll_tile_utils.c \
		$(PARSING)ft_ll_queue_utils.c \
		\
		$(HOOK)ft_key_hook.c \
		\
		$(MAP)ft_display_map.c \
		$(MAP)ft_open_images.c \
		$(MAP)ft_save_init_pos.c \
		\
		$(WINDOW)ft_close_window.c \
		$(WINDOW)ft_open_window.c \
		$(WINDOW)ft_open_map.c \
		\
		$(GAME)ft_move.c \
		$(GAME)ft_get_next_c.c \
		$(GAME)ft_game_end.c \

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -L./libft -lft $(MLX) -o $(NAME)

%.o : %.c
	@$(CC) $(FLAGS) -g -c $< -o $@ -Iinclude -Ilibft/include 

$(LIBFT): ./libft
	@make -C libft

test: fclean $(LIBFT)
	$(CC) $(FLAGS) src/test.c -g $(MLX) -L./libft -lft -I./libft/include -Iinclude -o test

map: all
	@echo "Map with bad extension"
	@./so_long maps/bad_extension.png

map2: all
	@echo "Map contain all components"
	@./so_long maps/miss_C_map.ber

map3: all
	@echo "Map contain a bad character"
	@./so_long maps/contain_J_map.ber

map4: all
	@echo "Map contain a redundant character"
	@./so_long maps/contain_two_E_map.ber

map5: all
	@echo "When map is not rectangular"
	@./so_long maps/no_rectangular_map.ber

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@rm -f test
	@rm -f $(NAME)
	@make clean -C libft

re:
	@make