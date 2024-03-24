SRCS=main \
utils/deg_to_rad \
level/feed_level \
level/load_level \
level/fit_level \
level/map_add \
level/parse_map \
level/check_map \
level/print_level \
level/load_textures \
level/unload_level \
window/pixel_put \
window/v_line \
window/new_window \
window/draw_circle \
game/loop \
game/load_game \
game/unload_game \
game/minimap \
events/keyboard \
events/mouse \
events/register_events \
engine/dda \
engine/raycasting \
engine/render \

NB := $(words $(SRCS))
CUR = 0
SRC=$(addsuffix .c, $(addprefix src/, $(addprefix ,$(SRCS))))
OBJ=$(SRC:.c=.o)
FLAGS=-Wall -Wextra -I inc -L libs/libft -L libs/minilibx-linux -lft -lmlx -lX11 -lXext -g3 -lm# -Werror
NAME=cub3d

all: mlx libft $(NAME)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(FLAGS)
	@/bin/echo -e "\nBuilding binary [$(NAME)]"

.c.o:
	@gcc -fPIC -c $< -o $@ $(FLAGS)
	$(eval CUR=$(shell echo $$(($(CUR)+1))))
	@/bin/echo -ne "Compiling sources [$(shell echo "$(CUR)*100/$(NB)" | bc)%] $@            \r"

clean:
	@$(RM) -rf $(OBJ)
	@make -C libs/minilibx-linux clean
	@make -C libs/libft clean
	@echo Cleaning compiled files

fclean: clean
	@$(RM) -rf $(NAME)
	@make -C libs/libft fclean
	@echo Cleaning binary

libft:
	@make -C libs/libft

mlx:
	@make -C libs/minilibx-linux

norm:
	norminette libs/libft
	norminette src/

re: fclean
	@make all
