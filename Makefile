NAME = push_swap.a

SOURCES =	push_swap.c ft_liblist.c sorting_algo.c swap_functions.c error_check.c \
			ft_is_sorted.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

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