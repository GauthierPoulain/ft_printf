_END=\033[0m
_BOLD=\033[1m
_UNDER=\033[4m
_REV=\033[7m

_RED=\033[31m
_GREEN=\033[32m
_YELLOW=\033[33m
_BLUE=\033[34m
_PURPLE=\033[35m
_CYAN=\033[36m
_WHITE=\033[37m

_IGREY=\033[40m
_IRED=\033[41m
_IGREEN=\033[42m
_IYELLOW=\033[43m
_IBLUE=\033[44m
_IPURPLE=\033[45m
_ICYAN=\033[46m
_IWHITE=\033[47m

NAME = libftprintf.a

CC = clang
CFLAGS = -Wall -Wextra -Werror -fno-builtin -O3

INCLUDES = ./includes

OBJS = $(SRCS:%.c=%.p)
SRCS = \

%.o: %.c $(INCLUDES)
	@printf "[ .. ] compile : $(_BOLD)$(<:.c=)$(_END)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\r$(_GREEN)[ OK ]$(_END)\n"

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft


clean:
	$(MAKE) clean -C ./libft
	# $(RM)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

update:
	git pull
	git pull --recurse-submodules

re: fclean all
