CC=cc
CFLAGS=-Wall -Wextra -Werror 
HEADER=minitalk.h
SERVER=server
CLIENT=client
SRCS_CLIENT= ./client.c ./utils.c
SRCS_SERVER= ./server.c ./utils.c

OBJS_CLIENT= $(SRCS_CLIENT:.c=.o)
OBJS_SERVER= $(SRCS_SERVER:.c=.o)

all: $(SERVER) $(CLIENT)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(SERVER)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: clean fclean all re
