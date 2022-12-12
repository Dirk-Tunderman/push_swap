NAME = libpush.a

SOURCES =	push_swap.c begin_list.c order_list.c


OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ./libft
	cp libft/libft.a $(NAME)
	gcc -c -Wall -Werror -Wextra $(SOURCES)
	ar -rcs $(NAME) $(OBJECTS)
 
clean:
	make clean -C ./libft
	rm -rf $(OBJECTS)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re:	fclean all