SRCS=main \
dda \
draw \
freeing \
keyboard \
level \
map_checker \
map \
move \
parser \
parser_colors \
raycaster \
print_level \

NB	:=	$(words $(SRCS))
CUR	:=	0

SRC		:=	$(addsuffix .c, $(addprefix src/, $(addprefix ,$(SRCS))))
OBJ		:=	$(SRC:.c=.o)
DEP		:=	$(OBJ:.o=.d)

CFLAGS	:=	-Wall -Wextra -Werror -I inc -g3
LDFLAGS	:=	-L libft -L minilibx-linux
LDLIBS	:=	-lft -lmlx -lX11 -lXext -lm
NAME	:=	cub3D

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a minilibx-linux/libmlx.a
	cc -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)
	@/bin/echo -e "\nBuilding binary [$(NAME)]"

-include $(DEP)

.c.o:
	@cc $(CFLAGS) -c -MMD -MP $< -o $@
	$(eval CUR=$(shell echo $$(($(CUR)+1))))
	@/bin/echo -ne "Compiling sources [$(shell echo "$(CUR)*100/$(NB)" | bc)%] $@            \r"

clean:
	@$(RM) -rf $(OBJ) $(DEP)
	@make -C minilibx-linux clean
	@make -C libft clean
	@echo Cleaning compiled files

fclean: clean
	@$(RM) -rf $(NAME)
	@make -C libft fclean
	@echo Cleaning binary

re: fclean
	@make -s all

libft/libft.a:
	@make -C libft

minilibx-linux/libmlx.a:
	@make -C minilibx-linux

norm:
	norminette libft/src/
	norminette libft/include/
	norminette src/
	norminette inc/cub3d.h
	norminette inc/color.h
	norminette inc/libft.h

test: all
	@echo Checking for missing params
	@read a
	@echo Ceil Color
	@./cub3D maps/missing_color_ceil.cub > /dev/null
	@echo Floor Color
	@./cub3D maps/missing_color_floor.cub > /dev/null
	@echo EA Texture
	@./cub3D maps/missing_ea_texture.cub > /dev/null
	@echo NO Texture
	@./cub3D maps/missing_no_texture.cub > /dev/null
	@echo SO Texture
	@./cub3D maps/missing_so_texture.cub > /dev/null
	@echo WE Texture
	@./cub3D maps/missing_we_texture.cub > /dev/null
	@echo "\n[\033[0;32mDone.\033[0m]\n"
	@echo Checking for map enclosures
	@read a
	@echo Bottom Side
	@./cub3D maps/not_enclosed_bottom.cub > /dev/null
	@echo Left Side
	@./cub3D maps/not_enclosed_left.cub > /dev/null
	@echo Right Side
	@./cub3D maps/not_enclosed_right.cub > /dev/null
	@echo Top Side
	@./cub3D maps/not_enclosed_top.cub > /dev/null
	@echo "\n[\033[0;32mDone.\033[0m]\n"
	@echo Checking for wrong texture file names
	@read a
	@echo EA Texture file
	@./cub3D maps/wrong_ea_texture_file.cub > /dev/null
	@echo NO Texture file
	@./cub3D maps/wrong_no_texture_file.cub > /dev/null
	@echo SO Texture file
	@./cub3D maps/wrong_so_texture_file.cub > /dev/null
	@echo WE Texture file
	@./cub3D maps/wrong_we_texture_file.cub > /dev/null
	@echo "\n[\033[0;32mDone.\033[0m]\n"
	@echo Checking for valid level
	@read a
	@./cub3D maps/basic_map.cub
	@echo "\n[\033[0;32mDone.\033[0m]\n"
	@read a
	@echo "\n[\033[0;32mTests Done.\033[0m]\n"
	@read a

.PHONY: test norm re fclean clean all libft
