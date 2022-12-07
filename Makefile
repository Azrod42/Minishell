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
FLAGS =-Wall -Werror -Wextra 
INCS	= .

.c.o :
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

all: $(NAME)

${NAME}: ${OBJS}
	@make -C ${LIBFTPATH}
	@echo "${_BOLD}${_UNDER}${_BLUE}Moving libft.a to .${_END}" && sleep 0.5
	@mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	@echo "${_BOLD}✅ ${_IGREEN}Done${_END}"
	@echo "${_BOLD}${_UNDER}${_BLUE}Making ${NAME}${_END}" && sleep 0.5
	@${CC} ${FLAGS} -lreadline ${OBJS} ${LIBFTNAME} -o ${NAME}
	@echo "${_BOLD}✅ ${_IGREEN}Done${_END}"
	@echo "${_BOLD}${_UNDER}${_RED}${_L0}\n${_L1}\n${_L2}\n${_L3}\n${_L4}\n${_L5}\n${_L6}\n${_L0}\n${_L7}\n${_L0}\n${_END}"
	@echo "${_BOLD}${_UNDER}${_RED}\nUsage : ./minishell${_END}"

clean:
	@echo "${_BOLD}${_UNDER}${_BLUE}Removing *.o ${LIBFTNAME}${_END}" && sleep 0.5
	@rm -rf *.o
	@echo "${_BOLD}✅ ${_IGREEN}Done${_END}"

fclean: clean
	@echo "${_BOLD}${_UNDER}${_BLUE}fclean ${LIBFTNAME}${_END}" && sleep 0.5
	@make fclean -C ${LIBFTPATH}
	@echo "${_BOLD}✅ ${_IGREEN}Done${_END}"
	@echo "${_BOLD}${_UNDER}${_BLUE}Removing $(OBJS) $(LIBFTNAME) $(NAME) ${LIBFTPATH}${_END}" && sleep 0.5
	@rm -rf $(OBJS) $(LIBFTNAME) $(NAME)
	@echo "${_BOLD}✅ ${_IGREEN}Done${_END}"

mclean: clean
	@echo "${_BOLD}${_UNDER}${_BLUE}Removing $(OBJS) $(LIBFTNAME) $(NAME) ${_END}" && sleep 0.5
	@rm -rf $(OBJS) $(LIBFTNAME) $(NAME)
	@echo "${_BOLD}✅ ${_IGREEN}Done${_END}"

norm:
	norminette ${SRCS} ${INCLUDE}

git_add:
	git add ${SRCS} ${INCLUDE} Makefile misc/* libft/*

git_push:
	git commit -md
	git push origin master

re: fclean all

ree: mclean all

# This is a minimal set of ANSI/VT100 color codes
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m

# Colors
_GREY=$'\x1b[30
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

# Inverted, i.e. colored backgrounds
_IGREY=$'\x1b[40m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m
_IBLUE=$'\x1b[44m
_IPURPLE=$'\x1b[45m
_ICYAN=$'\x1b[46m
_IWHITE=$'\x1b[47m

_L0=$'|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|'
_L1=$'| ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗      |
_L2=$'| ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║      |
_L3=$'| ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║      |
_L4=$'| ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║      |
_L5=$'| ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗ |
_L6=$'| ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ |
_L7=$'|               f|l|a|n|t|i|n|e| |&| |t|s|o|r|a|b|e|l|                |
