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

CFLAGS	+=	-W -Wall -Wextra -Werror
CLFAGS	+=	-Iinc

LDFLAGS	+=

NAME	=	serverJ2T3

SRCS	=	main.c

OBJS	=	$(SRCS:.c=.o)

all		:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
