##
## Makefile for jetpack2Tek3 in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016
## 
## Made by Valerian Vermeulen
## Login   <vermeu_v@epitech.net>
## 
## Started on  Wed Jul 19 12:05:39 2017 Valerian Vermeulen
## Last update Wed Jul 19 15:42:41 2017 Valerian Vermeulen
##

all		:
			make -C fold_server
			make -C fold_client

server	:
			make -C fold_server

client	:
			make -C fold_client

clean	:
			make -C fold_server clean
			make -C fold_client clean

fclean	:
			make -C fold_server fclean
			make -C fold_client fclean

re		:
			make -C fold_server re
			make -C fold_client re
