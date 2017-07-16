##
## Makefile for client in /home/loicpirez/CLionProjects/untitled
## 
## Made by Loïc Pirez
## Login   <loic.pirez@epitech.eu>
## 
## Started on  Thu Jul 13 13:58:08 2017 Loïc Pirez
## Last update Thu Jul 13 13:59:42 2017 Loïc Pirez
##

NAME	=	client

SRCS	=	$(shell cat sources.mk)

OBJS	=	$(SRCS:.c=.o)

DEPS	=	$(SRCS:.c=.d)

INCLUDE	=	-I include/	\

RM	=	rm -f

CFLAGS	+=	-W -Wall -pedantic -lSDL2 -lpthread

CFLAGS	+=	$(INCLUDE)	\

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

debug:		CFLAGS += -g

debug:		fclean

debug:		all

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
