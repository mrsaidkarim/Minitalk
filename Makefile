CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_C = Mandatory/client.c
SRC_S = Mandatory/server.c
SRC_U = Mandatory/utils.c
HEADER = minitalk.h
CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER)

$(CLIENT): $(SRC_C) $(SRC_U) $(HEADER)
	$(CC) $(CFLAGS) $(SRC_C) $(SRC_U) -o $@

$(SERVER): $(SRC_S) $(SRC_U) $(HEADER)
	$(CC) $(CFLAGS) $(SRC_S) $(SRC_U) -o $@

clean:
	rm -rf $(CLIENT) $(SERVER)

fclean:	clean

re: fclean all