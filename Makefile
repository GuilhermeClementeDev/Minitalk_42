# -*- MakeFile -*-

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFTNAME = libft.a

CLIENT= client.c
SERVER= server.c

CLIENT_OBJS= $(CLIENT:.c=.o)
SERVER_OBJS= $(SERVER:.c=.o)

CLIENT_BONUS= client_bonus.c
SERVER_BONUS= server_bonus.c

CLIENT_BONUS_OBJS= $(CLIENT_BONUS:.c=.o)
SERVER_BONUS_OBJS= $(SERVER_BONUS:.c=.o)

all: server client

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

makelib:
	@make -C ./lib
	@cp ./lib/$(LIBFTNAME) .

client: $(CLIENT_OBJS) makelib
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFTNAME) -o client

server: $(SERVER_OBJS) makelib
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFTNAME) -o server

client_bonus: $(CLIENT_BONUS_OBJS) makelib
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(LIBFTNAME) -o client_bonus

server_bonus: $(SERVER_BONUS_OBJS) makelib
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) $(LIBFTNAME) -o server_bonus

bonus: client_bonus server_bonus

clean:
	@rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)
	cd ./lib && make clean

fclean: clean
	@rm -f $(LIBFTNAME) client server client_bonus server_bonus
	cd ./lib && make fclean

re: fclean all
