##
## Makefile for client in /home/loicpirez/CLionProjects/untitled
## 
## Made by Loïc Pirez
## Login   <loic.pirez@epitech.eu>
## 
## Started on  Thu Jul 13 13:58:08 2017 Loïc Pirez
## Last update Wed Jul 19 12:23:35 2017 Loïc Pirez
##

CC	?=	gcc

NAME	=	../clientJ2T3

SRCS	=	$(shell cat sources.mk)

OBJS	=	$(SRCS:.c=.o)

DEPS	=	$(SRCS:.c=.d)

INCLUDE	=	-I include/ -I /usr/include/SDL/	\

RM	=	rm -f

LIB	=	-lSDL -lpthread

CFLAGS	+=	-W -Wall -pedantic

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(LIB) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

debug:		CFLAGS += -g

debug:		all

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.c.o:
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY:		all clean fclean re
