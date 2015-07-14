##
## Makefile for 42sh in /home/colin_h/rendu/On_going_project/PSU_2014_42sh
## 
## Made by François Colin
## Login   <colin_h@epitech.net>
## 
## Started on  Sun May 24 22:11:32 2015 François Colin
## Last update Sun May 24 22:11:33 2015 François Colin
##

SRC     =       source/main/main.c \
		source/lexer/epurstr.c \
		source/lexer/headlist.c \
		source/lexer/lexer.c \
		source/lexer/struct.c \
		source/main/pars_check.c \
		source/error/error.c \
		source/main/epur_space.c \
		source/main/prompt.c \
		source/main/my_exit.c \
		source/parser/pars.c \
		source/parser/path.c \
		source/lexer/get_next_line.c \
		source/parser/my_str_to_wordtab.c \
		source/parser/pars_global.c \
		source/error/error_exe.c \
		source/parser/echo_check.c \
		source/parser/exec.c \
		source/parser/strcat_spe.c \
		source/builtin/my_cd.c \
		source/builtin/my_setenv.c \
		source/main/my_getenv.c \
		source/error/my_free.c \
		source/builtin/my_unsetenv.c \
		source/builtin/check_builtins.c \
		source/parser/relativ_path.c \
		source/parser/parsnorme.c \
		source/parser/echo_path.c

NAME    =       42sh

OBJ     =       $(SRC:.c=.o)

CFLAGS  +=      -I include/ -Wall -Wextra -W

LDFLAGS +=      -L./lib -lmy

CC	=	gcc

RM	=	rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re: fclean all

test	:
	./moulinette/moul_42sh.sh
