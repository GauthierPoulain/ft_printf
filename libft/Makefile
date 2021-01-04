_END=\033[0m
_BOLD=\033[1m
_UNDER=\033[4m
_REV=\033[7m

_GREY=\033[30m
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


NAME = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror -fno-builtin -O3 -g

MAKE = make --no-print-directory

HEADER = ./libft.h

OBJS = $(SRCS:%.c=%.o)
SRCS = \
	ft_atoi.c \
	ft_atoi_base.c \
	ft_bzero.c  \
	ft_calloc.c \
	ft_convert_base.c \
	ft_count.c \
	ft_get_index.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c  \
	ft_ischarset.c \
	ft_isdigit.c \
	ft_isprint.c  \
	ft_isspace.c \
	ft_itoa.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_math_factorial.c \
	ft_math_fibonacci.c \
	ft_math_isprime.c \
	ft_math_max.c \
	ft_math_min.c \
	ft_math_nextprime.c \
	ft_math_power.c \
	ft_math_sqrt.c \
	ft_memccpy.c  \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c  \
	ft_memmove.c \
	ft_memset.c  \
	ft_nblen.c \
	ft_popnbr.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_realloc.c \
	ft_rev_tab.c \
	ft_split.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c  \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strndup.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_swap.c \
	ft_tolower.c  \
	ft_toupper.c  \
	ft_putstrn_fd.c \
	ft_itoa_base.c \
	ft_uitoa_base.c \
	ft_tolowercase.c \
	ft_touppercase.c \
	ft_uitoa.c \

%.o: %.c $(HEADER)
	@printf "[ $(_GREEN)$(_BOLD)>+$(_END) ][ compiling ] $(_BLUE)$(_BOLD)$<$(_END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@printf "[ $(_GREEN)$(_BOLD)>+$(_END) ][ building ] $(_BLUE)$(_BOLD)$(NAME)$(_END)\n"
	@$(AR) rcs $(NAME) $(OBJS)

re: fclean
	@$(MAKE) all

clean:
	@$(RM) $(OBJS)
	@printf "[ $(_RED)$(_BOLD)--$(_END) ][ removing ] $(_BLUE)$(_BOLD)objs $(_END)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "[ $(_RED)$(_BOLD)--$(_END) ][ removing ] $(_BLUE)$(_BOLD)$(NAME) $(_END)\n"

norm:
	@norminette *.[ch]

build: re
	@$(MAKE) clean

.PHONY: all re clean fclean norm build
