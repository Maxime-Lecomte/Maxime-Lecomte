##
## EPITECH PROJECT, 2020
## Semestre1
## File description:
## Makefile
##

SRC			=		copy_bg.c 			\
					create_button.c 	\
					create_sprite.c 	\
					create_window.c 	\
					print_message.c 	\
					print_text.c 		\
					trans_to_black.c 	\
					trans_to_picture.c 	\

CC			= 		@gcc

OBJ 		=		$(SRC:.c=.o)

CFLAGS 		= 		-Wall -Werror -Wextra -ggdb3

CPPFLAGS 	= 		-I./../../include/

NAME		= 		my_csfml.a

RM			= 		@rm -rf

RED 		= 		`tput setaf 1`
GREEN 		= 		`tput setaf 2`
CYAN 		= 		`tput setaf 6`
RESET		=		`tput sgr 0`

all:	msg_obj $(OBJ)
	@echo "${CYAN}=====        Library creation...        =====${RESET}"
	@ar rc $(NAME) $(OBJ)
	@mv $(NAME) ../../
	@echo "${GREEN}=====            Completed.             =====${RESET}"

msg_obj:
	@echo "${CYAN}=====    Creating library objects...    =====${RESET}"

clean:
	@echo "${RED}=====    Deleting library objects...    =====${RESET}"
	$(RM) $(OBJ) *.gc* vgcore*

fclean: 	clean
	@echo "${RED}=====      Deleting the library...      =====${RESET}"
	$(RM) ../../$(NAME)

re: 	fclean all

.PHONY: all clean fclean re