FUNCTIONS=isalpha isdigit isalnum isascii isprint strlen memset strlcpy \
	strlcat toupper tolower strchr strrchr strncmp memchr memcmp memcpy \
	memmove strnstr atoi calloc strdup \
	isspace substr strjoin strtrim split \
	itoa strmapi striteri putchar_fd putstr_fd putendl_fd putnbr_fd \
	lst_addback lst_addfront lstclear lstdelone lstiter lstlast lstmap lstnew lstsize \
	readline bzero get_next_line
NB := $(words $(FUNCTIONS))
CUR = 0
SRC=$(addsuffix .c, $(addprefix src/, $(addprefix ft_,$(FUNCTIONS))))
OBJ=$(SRC:.c=.o)
FLAGS=-Wall -Wextra -Werror -I include -g3
NAME=libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@/bin/echo -e "\nBuilding library [$(NAME)]"

.c.o:
	@cc -fPIC -c $< -o $@ $(FLAGS)
	$(eval CUR=$(shell echo $$(($(CUR)+1))))
	@/bin/echo -ne "Compiling sources [$(shell echo "$(CUR)*100/$(NB)" | bc)%] $@            \r"

clean:
	@$(RM) -rf $(OBJ)
	@echo Cleaning compiled files

fclean: clean
	@$(RM) -rf $(NAME)
	@echo Cleaning library

re: fclean 
	@make -s all
 
