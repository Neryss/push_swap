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

CHECKER = checker
PUSH = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -fno-builtin
SRCS =
OBJS = $(SRCS:%.o=%.c)


%.o: %.c
	@printf "$(_PURPLE)[$(PUSH)] $(_END)$(_CYAN)[+] $(_END)Compiling $(_BLUE)owo$(_END) | $(_CYAN)$<$(_END)\n" | tr "lr" "w"
	@$(CC) $< -o $(<:%.c=%.o)

all: $(CHECKER) $(PUSH)

$(CHECKER): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o checker $(OBJS) checker.c libft/libft.a
	@printf "$(_PURPLE)[$(CHECKER)] $(_END)$(_BLUE)[✓] $(_END)$(_UNDER)$(_BOLD)$(_GREEN)Done uwu$(_END)\n" | tr "lr" "w"

$(PUSH): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(PUSH) $(OBJS) push_swap.c libft/libft.a
	@printf "$(_PURPLE)[$(PUSH)] $(_END)$(_BLUE)[✓] $(_END)$(_UNDER)$(_BOLD)$(_GREEN)Done uwu$(_END)\n" | tr "lr" "w"

re: fclean
	@printf "$(_PURPLE)[$(PUSH)] $(_END)$(_RED)[-]$(_END) All cleaned up!\n" | tr "lr" "w"
	@$(MAKE) all

clean:
	@printf "$(_PURPLE)[$(PUSH)] $(_END)$(_RED)[-]$(_END) Objects deleted!\n"
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(PUSH) $(CHECKER)

norme:
	norminette srcs/ checker.c push_swap.c