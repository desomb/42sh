##
## Makefile for lib in /home/colin_h/rendu/Piscine_C_J11/lib/my
## 
## Made by François Colin
## Login   <colin_h@epitech.net>
## 
## Started on  Mon Oct 20 09:07:50 2014 François Colin
## Last update Sun May 24 23:02:38 2015 François Colin
##

SRC= my_putchar.c \
     my_strdup.c \
     my_isneg.c \
     my_put_nbr.c \
     my_swap.c \
     my_putstr.c \
     my_strlen.c \
     my_getnbr.c \
     my_sort_int_tab.c \
     my_power_rec.c \
     my_square_root.c \
     my_is_prime.c \
     my_find_prime_sup.c \
     my_strcpy.c \
     my_strncpy.c \
     my_revstr.c \
     my_strstr.c \
     my_strcmp.c \
     my_strncmp.c \
     my_strupcase.c \
     my_strlowcase.c \
     my_strcapitalize.c \
     my_str_isalpha.c \
     my_str_isnum.c \
     my_str_islower.c \
     my_str_isupper.c \
     my_str_isprintable.c \
     my_showstr.c \
     my_showmem.c \
     my_strcat.c \
     my_strncat.c \
     my_strlcat.c \
     my_strdup.c

OBJ= $(SRC:.c=.o)

NAME= libmy.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
