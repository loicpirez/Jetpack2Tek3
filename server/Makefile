##
## Makefile for jetpack2Tek3 in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016
## 
## Made by Valerian Vermeulen
## Login   <vermeu_v@epitech.net>
## 
## Started on  Sat Jul 15 17:27:27 2017 Valerian Vermeulen
## Last update Sat Jul 15 17:31:57 2017 Valerian Vermeulen
##

CC		=	gcc

RM		=	rm -rf

CFLAGS	+=	-W -Wall -Wextra -Werror -g ## TODO : remove -g
CFLAGS	+=	-Iinc
CFLAGS	+=	-Iinc/Map_Functions_Headers
CFLAGS	+=	-Iinc/Player_Functions_Headers
CFLAGS	+=	-Iinc/Socket_Functions_Headers
CFLAGS	+=	-Iinc/Socket_Functions_Headers/Command_Functions_Headers

LDFLAGS	+=

NAME	=	serverJ2T3

SRC	=	src/

MAP	=	src/Map_Handling/

PLAYER	=	src/Player_Handling/

SOCKET	=	src/Sock_Handling/

CMD	=	src/Sock_Handling/Cmd_Handling/

SRCS	=	$(SRC)main.c \
		$(MAP)init_map.c \
		$(MAP)open_file.c \
		$(PLAYER)init_player.c \
		$(SOCKET)init_socket.c \
		$(CMD)coin_cmd.c \
		$(CMD)finish_cmd.c \
		$(CMD)fire_cmd.c \
		$(CMD)id_cmd.c \
		$(CMD)map_cmd.c \
		$(CMD)player_cmd.c \
		$(CMD)ready_cmd.c \
		$(CMD)start_cmd.c

OBJS	=	$(SRCS:.c=.o)

all		:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
