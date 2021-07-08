##
## EPITECH PROJECT, 2020
## matchstick
## File description:
## Makefile
##

SRC				=		game/dialogue/dialogue.c 				\
						game/dialogue/init_dialogue.c			\
						game/event/event.c 						\
						game/event/init_event.c 				\
						game/event/interact.c 					\
						game/event/teleport.c 					\
						game/fight/attack.c						\
						game/fight/click.c 						\
						game/fight/draw.c 						\
						game/fight/enemy.c 						\
						game/fight/fight.c 						\
						game/initialization/download_map.c		\
						game/initialization/init_box.c 			\
						game/initialization/init_map.c 			\
						game/initialization/init_perso.c 		\
						game/initialization/initialization.c 	\
						game/inventory/delete.c 				\
						game/inventory/drag.c 					\
						game/inventory/drop.c 					\
						game/inventory/inventory.c 				\
						game/inventory/manage_click.c			\
						game/pause/analyse_event.c				\
						game/pause/pause.c 						\
						game/analyse_event.c					\
						game/free.c 							\
						game/game.c 							\
						game/move_player.c 						\
						game/print_map.c 						\
						game/status.c 							\
						menu/analyse_event.c					\
						menu/controls.c							\
						menu/draw.c 							\
						menu/initialization.c					\
						menu/menu.c 							\
						menu/settings.c							\
						music/music.c 							\
						error.c 								\
						help.c 									\

SRC_MAIN		=		main.c

DIR_SRC			=		$(addprefix src/, $(SRC))

DIR_SRC_MAIN	=		$(addprefix src/, $(SRC_MAIN))

OBJ				=		$(DIR_SRC:.c=.o)

OBJ_MAIN		=		$(DIR_SRC_MAIN:.c=.o)

CC				=		@gcc

CFLAGS			=		-Wall -Wextra -ggdb3

CPPFLAGS		=		-I./include/

LDFLAGS			=		-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -L. utils.a -L. my_csfml.a

UTFLAGS 		= 		--coverage -lcriterion

NAME			=		my_rpg

UNIT_NAME 		= 		unit_tests

RM				=		@rm -rf

RED				=		`tput setaf 1`
GREEN 			= 		`tput setaf 2`
YELLOW			=		`tput setaf 3`
RESET			=		`tput sgr 0`

all:	lib msg_obj $(OBJ) $(OBJ_MAIN)
	@echo "$(YELLOW)=====    Creation of executables...     =====${RESET}"
	$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS)
	@echo "${GREEN}=====            Completed.             =====${RESET}"

msg_obj:
	@echo "${YELLOW}=====        Creating objects...        =====${RESET}"

lib:
		@make -s -C lib/my_csfml
		@make -s -C lib/utils

lib_fclean:
		@make fclean -s -C lib/my_csfml
		@make fclean -s -C lib/utils

clean:
			@echo "${RED}=====       Deleting objects...         =====${RESET}"
			$(RM) $(OBJ) $(OBJ_MAIN) vgcore* *.gc*
			@echo "${GREEN}=====            Completed.             =====${RESET}"

fclean: 	lib_fclean clean
			$(RM) $(NAME)
			$(RM) $(UNIT_NAME)

re: 		fclean all

.PHONY: all lib lib_fclean clean fclean re
