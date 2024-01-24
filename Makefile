CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_C = Mandatory/client.c
OBJ_C = ${SRC_C:.c=.o}
SRC_S = Mandatory/server.c
OBJ_S = ${SRC_S:.c=.o}
SRC_U = Mandatory/utils.c
OBJ_U = ${SRC_U:.c=.o}
SRC_BNS_C = bonus/client_bonus.c
OBJ_BNS_C = ${SRC_BNS_C:.c=.o}
SRC_BNS_S = bonus/server_bonus.c
OBJ_BNS_S = ${SRC_BNS_S:.c=.o}
SRC_BNS_U = bonus/utils_bonus.c
OBJ_BNS_U = ${SRC_BNS_U:.c=.o}
HEADER = minitalk.h
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_C) $(OBJ_U)
	$(CC) $(CFLAGS) $(OBJ_C) $(OBJ_U) -o $@

$(SERVER): $(OBJ_S) $(OBJ_U)
	$(CC) $(CFLAGS) $(OBJ_S) $(OBJ_U) -o $@

$(CLIENT_BONUS): $(OBJ_BNS_C) $(OBJ_BNS_U)
	$(CC) $(CFLAGS) $(OBJ_BNS_C) $(OBJ_BNS_U) -o $@

$(SERVER_BONUS): $(OBJ_BNS_S) $(OBJ_BNS_U)
	$(CC) $(CFLAGS) $(OBJ_BNS_S) $(OBJ_BNS_U) -o $@

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

clean:
	rm -rf $(OBJ_C) $(OBJ_S) $(OBJ_U) $(OBJ_BNS_C) $(OBJ_BNS_S) $(OBJ_BNS_U)

fclean:	clean
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: clean