##
## Makefile for Makefile in /home/thibaut.jacquart/Rendu/tek2/CPP/cpp_indie_studio/src/Linux/test
## 
## Made by Thibaut Jacquart
## Login   <thibaut.jacquart@epitech.net>
## 
## Started on  Sat May  6 16:34:30 2017 Thibaut Jacquart
## Last update Wed May 31 16:43:49 2017 Thibaut Jacquart
##

NAME		=	test

SRC		=	./../DefaultMenuInterface.cpp \
			./../DefaultGameInterface.cpp \
			./../MenuInterface.cpp \
			./../GameInterface.cpp \
			./../MenuModule.cpp \
			./../StatModule.cpp \
			./../ActionModule.cpp \
			./../InfoModule.cpp \
			./../MapModule.cpp \
			./../PauseModule.cpp \
			./main.cpp

OBJ		=	$(SRC:.cpp=.o)

CPPFLAGS	+=	-Wall -W -Wextra -I ./../../../include -g3

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			g++ -o $(NAME) $(OBJ)

clean		:
			rm -rf $(OBJ)

fclean		:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY		:	clean fclean all re
