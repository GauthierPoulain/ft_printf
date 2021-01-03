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
MAKE = make --no-print-directory

HEADER = includes/libft_printf.h
SRC_DIR = src

SRC = \
	ft_printf.c \
	flags_init.c \
	parse_flags.c \
	get_types.c \
	print_int.c \
	print_utils.c \
	print_int_utils.c \
	print_char.c \
	print_string.c \
	print_pointer.c \
	print_unisgned.c \
	print_base.c \
	print_percent.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(SRC_DIR)/, $(addsuffix .o, $(basename $(SRC))))

$(SRC_DIR)/%.o: ${SRC_DIR}/%.c $(HEADER)
	@printf "[ $(_GREEN)$(_BOLD)>+$(_END) ][ compiling ] $(_BLUE)$(_BOLD)$<$(_END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@printf "[ $(_PURPLE)$(_BOLD)>>$(_END) ][ copying ] $(_BLUE)$(_BOLD)libft/libft.a$(_END) to $(_BLUE)$(_BOLD)$(NAME)$(_END)\n"
	@cp libft/libft.a $(NAME)
	@printf "[ $(_GREEN)$(_BOLD)>+$(_END) ][ building ] $(_BLUE)$(_BOLD)$(NAME)$(_END)\n"
	@$(AR) rcs $(NAME) $(OBJS)

clean:
	@find ./src -name "*.o" -delete -printf "[ $(_RED)$(_BOLD)--$(_END) ][ removing ] $(_BLUE)$(_BOLD)%f $(_END)\n"
	@$(MAKE) clean -C ./libft

fclean: clean
	@find . -name "$(NAME)" -delete -printf "[ $(_RED)$(_BOLD)--$(_END) ][ removing ] $(_BLUE)$(_BOLD)%f $(_END)\n"
	@$(MAKE) fclean -C ./libft

re: fclean
	@$(MAKE) all

test: comp
	@printf "[ $(_BLUE)$(_BOLD)>>$(_END) ][ processing ] $(_BLUE)$(_BOLD)test$(_END)\n"
	@./test
	@printf "[ $(_GREEN)$(_BOLD):)$(_END) ][ done ] $(_BLUE)$(_BOLD)test$(_END)\n"

comp: all
	@printf "[ $(_GREEN)$(_BOLD)>+$(_END) ][ compiling ] $(_BLUE)$(_BOLD)test$(_END)\n"
	@${CC} ${CFLAGS} main.c -L. -lftprintf -o test

norm:
	norminette **/**.[ch]
	norminette *.[ch]

.PHONY: all clean fclean re test comp norm