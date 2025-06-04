# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 17:12:33 by josemigu          #+#    #+#              #
#    Updated: 2025/05/28 18:52:29 by josemigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
N_CHECKER = checker

# Paths
S_PATH			= src
S_CHECKER_PATH	= src_checker
I_PATH			= includes
I_CHECKER_PATH	= includes_checker
B_PATH			= build
B_CHECKER_PATH	= build_checker
LIBFT_PATH		= libft
LIBFT			= libft.a
I_LIBFT			= includes

# Sources
SRCS = $(addprefix $(S_PATH)/, \
		push_swap.c utils.c print_stack.c check_arguments.c initialization.c \
		operations_basic.c operations_swap.c operations_push.c \
		operations_rotate.c operations_reverse_rotate.c sort_stack.c \
		sort_radix.c sort_turk.c nodes_info_a_b.c nodes_info_b_a.c )

SRCS_CHECKER = $(addprefix $(S_CHECKER_PATH)/, \
		checker_bonus.c utils_bonus.c print_stack_bonus.c \
		check_arguments_bonus.c initialization_bonus.c \
		operations_basic_bonus.c operations_swap_bonus.c \
		operations_push_bonus.c process_input_bonus.c \
		operations_rotate_bonus.c operations_reverse_rotate_bonus.c )

# Objects
OBJS = $(addprefix $(B_PATH)/, $(notdir $(SRCS:.c=.o)))
O_CHECKER = $(addprefix $(B_CHECKER_PATH)/, $(notdir $(SRCS_CHECKER:.c=.o)))

CC					= cc
INCLUDES			= -I$(I_PATH) -I$(LIBFT_PATH)/$(I_LIBFT)
INCLUDES_CHECKER	= -I$(I_CHECKER_PATH) -I$(LIBFT_PATH)/$(I_LIBFT)
CFLAGS				= -Wall -Wextra -Werror $(INCLUDES) -g
CFLAGS_CHECKER		= -Wall -Wextra -Werror $(INCLUDES_CHECKER) -g
RM					= rm -f
MKDIR-P				= mkdir -p

all: ${NAME}

$(B_PATH):
	$(MKDIR-P) $(B_PATH)

$(B_CHECKER_PATH):
	$(MKDIR-P) $(B_CHECKER_PATH)

$(B_PATH)/%.o: $(S_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(B_CHECKER_PATH)/%.o: $(S_CHECKER_PATH)/%.c
	$(CC) $(CFLAGS_CHECKER) -c $< -o $@

$(NAME): $(B_PATH) $(OBJS)
	@${MAKE} -C $(LIBFT_PATH)
	@${CC} ${CFLAGS} ${OBJS} $(LIBFT_PATH)/$(LIBFT) -o ${NAME}

bonus: $(B_CHECKER_PATH) $(O_CHECKER)
	@${MAKE} -C $(LIBFT_PATH)
	@${CC} ${CFLAGS_CHECKER} ${O_CHECKER} $(LIBFT_PATH)/$(LIBFT) -o ${N_CHECKER}

clean: 
	@${MAKE} -C $(LIBFT_PATH) fclean
	@${RM} ${OBJS}
	@${RM} ${O_CHECKER}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${N_CHECKER}

re: fclean all

.PHONY: all clean fclean re bonus

OS = $(shell uname)

size ?= 42

ifeq ($(OS),Linux)
CHECKER = valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)
else
CHECKER = ./push_swap $(ARG) | ./checker_Mac $(ARG)
endif

test:
	@$(eval ARG = $(shell seq -1000 1000 | shuf -n $(size)))
	@echo "Checker result: "
	$(CHECKER)
	@echo "Instructions count: "
	@./push_swap $(ARG) | wc -l
