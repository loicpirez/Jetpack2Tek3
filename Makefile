##
## Makefile for jetpack2Tek3 in /home/vermeu_v/Documents/Synthesis_Pool/jetpack2Tek3_2016
## 
## Made by Valerian Vermeulen
## Login   <vermeu_v@epitech.net>
## 
## Started on  Wed Jul 19 12:05:39 2017 Valerian Vermeulen
## Last update Wed Jul 19 13:56:58 2017 Valerian Vermeulen
##

all		:
			make -C server
			make -C client

clean	:
			make -C server clean
			make -C client clean

fclean	:
			make -C server fclean
			make -C client fclean

re		:
			make -C server re
			make -C client re
