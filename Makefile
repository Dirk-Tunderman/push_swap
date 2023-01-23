NAME = libpush.a

SOURCES =	push_swap.c ft_liblist.c sorting_algo.c swap_functions.c error_check.c \
			swap_functions_2.c sort_little.c ft_liblist_2.c make_list.c \

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	make -C ./ftprintf
	cp ftprintf/libftprintf.a $(NAME)
	gcc -c -Wall -Werror -Wextra $(SOURCES)
	ar -rcs $(NAME) $(OBJECTS)
 
clean:
	make clean -C ./ftprintf
	rm -rf $(OBJECTS)

fclean: clean
	make fclean -C ./ftprintf
	rm -rf $(NAME)

re:	fclean all