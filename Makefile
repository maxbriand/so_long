NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra
SRC_DIR = ./src
LIBFT = libft/libft.a
MLX = -lmlx -lX11 -lXext

VALIDATION = src/validation/


SRC = 	src/main.c \
			\
			$(VALIDATION)ft_validation.c \
			$(VALIDATION)ft_validation_map_extension.c \
			$(VALIDATION)ft_validation_map_components.c \

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

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@rm -f test
	@rm -f $(NAME)
	@make clean -C libft

re:
	@make