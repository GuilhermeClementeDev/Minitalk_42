# -*- MakeFile -*-

CC = cc

NAME = test.a

LIBFTNAME = libft.a

MY_SOURCES =

CFLAGS = -Wall -Wextra -Werror

OBJ = $(MY_SOURCES:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

makelib:
	make -C ./lib
	@cp ./lib/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): $(OBJ) makelib
	ar -rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	cd ./lib && make clean

fclean: clean
	@rm -f $(NAME)
	cd ./lib && make fclean

re: fclean all
