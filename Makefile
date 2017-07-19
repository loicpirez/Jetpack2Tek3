##
## Makefile for jetpack2Tek3 in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016
## 
## Made by Valerian Vermeulen
## Login   <vermeu_v@epitech.net>
## 
## Started on  Wed Jul 19 12:05:39 2017 Valerian Vermeulen
## Last update Wed Jul 19 12:17:28 2017 Valerian Vermeulen
##

CC		=	gcc

RM		=	rm -rf

all		:
			cd server && make
			cd client && make

clean	:
			cd server && make clean
			cd client && make clean

fclean	:
			cd server && make fclean
			cd client && make fclean

re		:
			cd server && make re
			cd client && make re
