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
CC = clang
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/parsing.c \
		srcs/close.c \
		srcs/utils.c \
		srcs/moves/get_exe_moves.c \
		srcs/moves/moves_a.c \
		srcs/moves/moves_b.c \
		srcs/moves/moves_utils.c \
		srcs/algo/algo.c \
		srcs/algo/algo_moves.c \
		srcs/algo/algo_utils.c \
		srcs/algo/algo_utils2.c \
		srcs/algo/algo_six_to_hundred.c \
		srcs/algo/small_algos.c \
		srcs/algo/algo_median.c \
		srcs/algo/algo_hundreds.c \
		srcs/algo/push_quartiles.c
OBJS = $(SRCS:.c=.o)


%.o: %.c includes/push_swap.h
	@printf "$(_PURPLE)[$(PUSH)] $(_END)$(_CYAN)[+] $(_END)Compiling $(_BLUE)owo$(_END) | $(_CYAN)$<$(_END)\n" | tr "lr" "w"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(CHECKER) $(PUSH)

$(CHECKER): $(OBJS) checker.o
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) -o checker $(OBJS) checker.c libft/libft.a
	@printf "$(_PURPLE)[$(CHECKER)] $(_END)$(_BLUE)[✓] $(_END)$(_UNDER)$(_BOLD)$(_GREEN)Done uwu$(_END)\n" | tr "lr" "w"

$(PUSH): $(OBJS) push_swap.o
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) -o $(PUSH) $(OBJS) push_swap.c libft/libft.a
	@printf "$(_PURPLE)[$(PUSH)] $(_END)$(_BLUE)[✓] $(_END)$(_UNDER)$(_BOLD)$(_GREEN)Done uwu$(_END)\n" | tr "lr" "w"

re: fclean
	@printf "$(_PURPLE)[$(PUSH)] $(_END)$(_RED)[-]$(_END) All cleaned up!\n" | tr "lr" "w"
	@$(MAKE) all

clean:
	@$(MAKE) clean -C ./libft
	@printf "$(_PURPLE)[$(PUSH)] $(_END)$(_RED)[-]$(_END) Objects deleted!\n"
	@rm -f $(OBJS)
	@rm -f checker.o push_swap.o

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(PUSH) $(CHECKER)

norme:
	@norminette srcs/*.c checker.c push_swap.c includes/ libft

.PHONY: re clean fclean norme
