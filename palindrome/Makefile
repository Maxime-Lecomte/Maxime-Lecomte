##
## EPITECH PROJECT, 2020
## palindrome
## File description:
## Makefile
##

SRC				=		error.c		\
						palindrome.c	\
						n_arg.c	\
						p_arg.c	\
						fonction.c	\
						other_base.c	\

SRC_MAIN		=		main.c

DIR_SRC			=		$(addprefix src/, $(SRC))

DIR_SRC_MAIN	=		$(addprefix src/, $(SRC_MAIN))

OBJ				=		$(DIR_SRC:.c=.o)

OBJ_MAIN		=		$(DIR_SRC_MAIN:.c=.o)

CC				=		@gcc

CFLAGS			=		-Wall -Wextra -ggdb3

CPPFLAGS		=		-I./include/

LDFLAGS			=		-L. lib.a

UTFLAGS 		= 		--coverage -lcriterion

NAME			=		palindrome

UNIT_NAME 		= 		unit_tests

RM				=		@rm -rf

RED				=		`tput setaf 1`
GREEN 			= 		`tput setaf 2`
YELLOW			=		`tput setaf 3`
RESET			=		`tput sgr 0`

all:	lib msg_obj $(OBJ) $(OBJ_MAIN)
	@echo "$(YELLOW)====>    Creation of executables...     <====${RESET}"
	$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS)
	@echo "${GREEN}====>            Completed.             <====${RESET}"

msg_obj:
	@echo "${YELLOW}====>        Creating objects...        <====${RESET}"

lib:
		@make -s -C lib/

lib_fclean:
		@make fclean -s -C lib/

clean:
			@echo "${RED}====>       Deleting objects...         <====${RESET}"
			$(RM) $(OBJ) $(OBJ_MAIN) vgcore* *.gc*
			@echo "${GREEN}====>            Completed.             <====${RESET}"

fclean: 	lib_fclean clean
			$(RM) $(NAME)
			$(RM) $(UNIT_NAME)

re: 		fclean all

.PHONY: all lib lib_fclean clean fclean re
