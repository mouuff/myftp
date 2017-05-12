##
## Makefile for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
## 
## Made by arnaud.alies
## Login   <arnaud.alies@epitech.eu>
## 
## Started on  Fri May 12 15:02:28 2017 arnaud.alies
## Last update Fri May 12 17:19:37 2017 arnaud.alies
##

NAME	=	server

CC	=	gcc

INC	=	./include/

CFLAGS	=	-I$(INC) \
		-Wall -Wextra

LDFLAGS	+=

SRC	=	./src/

SRCS	=	$(SRC)main.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
