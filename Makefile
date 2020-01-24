#
# EPITECH PROJECT, 2019
# Makefile
# File description:
# make an executable
#

SRC =	main.c debug.c print_map.c \
		ia_file.c handle_error.c init_map.c my_event.c \
		update.c loose_win_state.c erasable.c
OBJ = $(SRC:.c=.o)
NAME = matchstick

CFLAGS += -I ./include/
CFLAGS += -L ./lib/
CFLAGS += -lmy

bold = [1m
green = [32m
yellow = [33m
blue = [34m
reset = (B[m

all: $(NAME)

lib_make:
	@make -C lib/my

$(NAME): lib_make $(OBJ)
	@echo '$(bold)$(green)Creating the $(NAME)...$(reset)'
	@gcc -g3 -o $(NAME) $(OBJ) $(CFLAGS)
	@echo '$(bold)$(yellow)Executable created...$(reset)'
clean:
	@echo '$(bold)$(blue)Clean the directory in process...$(reset)'
	@rm -f $(OBJ)
	@echo '$(bold)$(yellow)Executable cleaned..$(reset)'

fclean: clean
	@rm -f $(NAME)
	@make fclean -C lib/my

re: fclean all