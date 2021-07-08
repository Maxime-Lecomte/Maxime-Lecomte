##
## EPITECH PROJECT, 2020
## palindrome
## File description:
## Makefile
##


SRC			=		my_getnbr.c \
					my_put_nbr.c	\
					my_putchar.c	\
					my_putstr.c	\
					my_revstr.c	\
					my_strcmp.c	\
					my_strisnum.c	\
					my_swap.c	\
					printf_advancedflag.c	\
					printf_easyflag.c	\
					printf_main.c	\
					my_strlen.c	\

CC			= 		@gcc

OBJ 		=		$(SRC:.c=.o)

CFLAGS 		= 		-Wall -Werror -Wextra -ggdb3

CPPFLAGS 	= 		-I./../include/

NAME		= 		lib.a

RM			= 		@rm -rf

RED 		= 		`tput setaf 1`
GREEN 		= 		`tput setaf 2`
CYAN 		= 		`tput setaf 6`
RESET		=		`tput sgr 0`

all:	msg_obj $(OBJ)
	@echo "${CYAN}====>        Library creation...        <====${RESET}"
	@ar rc $(NAME) $(OBJ)
	@mv $(NAME) ../
	@echo "${GREEN}====>            Completed.             <====${RESET}"

msg_obj:
	@echo "${CYAN}====>    Creating library objects...    <====${RESET}"

clean:
	@echo "${RED}====>    Deleting library objects...    <====${RESET}"
	$(RM) $(OBJ) *.gc* vgcore*

fclean: 	clean
	@echo "${RED}====>      Deleting the library...      <====${RESET}"
	$(RM) ../$(NAME)

re: 	fclean all

.PHONY: all clean fclean re