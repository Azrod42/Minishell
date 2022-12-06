NAME = minishell

LIBFTNAME = libft.a
LIBFTPATH = ./libft/

SRCS = srcs/main.c \

INCLUDE = include/minishell.h \

OBJS	= $(SRCS:.c=.o)
FLAGS =-Wall -Werror -Wextra
DEBUG = -g -O0
INCS	= .

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

all: $(NAME)

${NAME}: ${OBJS}
	make -C ${LIBFTPATH}
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${CC} ${FLAGS} ${OBJS} ${LIBFTNAME} -o ${NAME}

clean:
	rm -rf *.o

fclean: clean
	make fclean -C ${LIBFTPATH}
	rm -rf $(OBJS) $(LIBFTNAME) $(NAME)

norm:
	norminette ${SRCS} ${INCLUDE}

git add:
	git init
	git add ${SRCS} ${INCLUDE} Makefile

re: fclean all