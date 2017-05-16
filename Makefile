##
## Makefile for hue in /home/arnaud.alies/rendu/PSU_2016_myftp
## 
## Made by arnaud.alies
## Login   <arnaud.alies@epitech.eu>
## 
## Started on  Fri May 12 15:02:28 2017 arnaud.alies
## Last update Tue May 16 13:42:26 2017 arnaud.alies
##

NAME	=	server

CC	=	gcc

INC	=	./include/

CFLAGS	=	-I$(INC) \
		-Wall -Wextra

LDFLAGS	+=

SRC	=	./src/

SRC_CMD	=	$(SRC)cmd/

SRC_MY	=	$(SRC)my/

SRCS	=	$(SRC)main.c \
		$(SRC)server.c \
		$(SRC)ftp.c \
		$(SRC)clean.c \
		$(SRC_CMD)quit.c \
		$(SRC_CMD)run.c \
		$(SRC_CMD)user.c \
		$(SRC_CMD)pass.c \
		$(SRC_CMD)pwd.c \
		$(SRC_MY)malloc.c \
		$(SRC_MY)strdup.c \
		$(SRC_MY)str_args.c \

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
