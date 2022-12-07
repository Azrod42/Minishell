NAME = minishell

LIBFTNAME = libft.a
LIBFTPATH = ./libft/

SRCS = srcs/main.c \
		srcs/prompt.c \
		srcs/redirect.c \
		srcs/ft_exit.c

INCLUDE = include/minishell.h \

OBJS	= $(SRCS:.c=.o)
DEBUG = -g -O0
FLAGS =-Wall -Werror -Wextra -g 
INCS	= .

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

all: $(NAME)

${NAME}: ${OBJS}
	make -C ${LIBFTPATH}
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${CC} ${FLAGS} -lreadline ${OBJS} ${LIBFTNAME} -o ${NAME}

clean:
	rm -rf *.o

fclean: clean
	make fclean -C ${LIBFTPATH}
	rm -rf $(OBJS) $(LIBFTNAME) $(NAME)

mclean: clean
	rm -rf $(OBJS) $(LIBFTNAME) $(NAME)

norm:
	norminette ${SRCS} ${INCLUDE}

git_add:
	git add ${SRCS} ${INCLUDE} Makefile misc/* libft/*

git_push:
	git commit -md
	git push origin master

re: fclean all

ree: mclean all
