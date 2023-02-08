CC =	gcc
FLAGS =	-Wall -Werror -Wextra
AR =	ar -rcs
RM =	rm -f

NAME =	client
NAMES =	server

all: $(NAME) $(NAMES)

$(NAMES): server.c utils.c
	$(CC) $(FLAGS) server.c utils.c -o $(NAMES)

$(NAME): client.c utils.c
	$(CC) $(FLAGS) client.c utils.c -o $(NAME)

clean:

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAMES)

re:	fclean all
