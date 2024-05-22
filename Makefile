CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = client.c server.c

MINITALK = client server 
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

all: ${SERVER} ${CLIENT}

bonus: ${SERVER_BONUS} ${CLIENT_BONUS}

$(CLIENT): client.c utils.c
	${CC} ${CFLAGS} -o $@ $^

$(SERVER): server.c utils.c
	${CC} ${CFLAGS} -o $@ $^

$(SERVER_BONUS): server_bonus.c utils_bonus.c
	${CC} ${CFLAGS} -o $@ $^

$(CLIENT_BONUS): client_bonus.c utils_bonus.c
	${CC} ${CFLAGS} -o $@ $^

clean:
	${RM} ${OBJ} 

fclean:
	${RM} ${OBJ} ${MINITALK} ${SERVER_BONUS} ${CLIENT_BONUS}

re: fclean all

.PHONY: all clean fclean re bonus