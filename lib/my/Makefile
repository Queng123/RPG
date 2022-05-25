##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC	=	functions/my_putstr.c							\
		functions/my_putchar.c							\
		functions/my_compute_power_rec.c				\
		functions/my_compute_square_root.c				\
		functions/my_find_prime_sup.c					\
		functions/my_getnbr.c							\
		functions/my_isneg.c							\
		functions/my_is_prime.c							\
		functions/my_put_nbr.c							\
		functions/my_revstr.c							\
		functions/my_showmem.c							\
		functions/my_showstr.c							\
		functions/my_sort_int_array.c					\
		functions/my_strcapitalize.c					\
		functions/my_strcat.c							\
		functions/my_strcmp.c							\
		functions/my_strcpy.c							\
		functions/my_str_isalpha.c						\
		functions/my_str_islower.c						\
		functions/my_str_isnum.c						\
		functions/my_str_isprintable.c					\
		functions/my_str_isupper.c						\
		functions/my_strlen.c							\
		functions/my_strlowcase.c						\
		functions/my_strncat.c							\
		functions/my_strncmp.c							\
		functions/my_strncpy.c							\
		functions/my_strstr.c							\
		functions/my_strupcase.c						\
		functions/my_swap.c								\
		functions/my_strtol.c							\
		functions/my_itoa.c								\
		functions/my_printf/print_fonctions.c			\
		functions/my_printf/print_hexa.c				\
		functions/my_printf/my_binary_conversion.c		\
		functions/my_printf/my_print_adress.c			\
		functions/my_printf/my_printf.c					\
		functions/my_printf/my_put_bigstr.c				\
		functions/my_printf/my_put_nbr_unsigned.c		\
		functions/my_strdup.c							\
		functions/my_calloc.c 							\
		functions/my_memset.c							\
		functions/mem_alloc_2d_array.c 					\
		functions/load_2d_arr_from_file.c				\
		functions/print_array_str.c						\
		functions/fs_open_file.c						\
		functions/free_double_array.c					\
		functions/my_array_len.c						\
		functions/my_arraycat.c							\
		functions/my_arraydup.c 						\
		functions/my_arraycpy.c 						\
		functions/get_width.c							\
		functions/int_to_char.c							\
		functions/my_str_to_word_array.c 				\

CC 	= gcc

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)
		mv $(NAME) ../
		cp -r include/ ../../

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
		rm -rf ../../libmy.a

re:	fclean all

.PHONY: fclean clean re all
