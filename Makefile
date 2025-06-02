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

# Paths
SRC_PATH		= src
LIBFT_PATH		= libft
LIBFT			= libft.a
INCLUDES_PATH	= includes
BUILD_PATH		= build

# Sources
SRCS = $(addprefix $(SRC_PATH)/, \
		push_swap.c utils.c print_stack.c check_arguments.c initialization.c \
		operations_basic.c operations_swap.c operations_push.c \
		operations_rotate.c operations_reverse_rotate.c sort_stack.c \
		sort_radix.c sort_turk.c nodes_info_a_b.c nodes_info_b_a.c )

# Objects
OBJS = $(addprefix $(BUILD_PATH)/, $(notdir $(SRCS:.c=.o)))

CC			= cc
INCLUDES	= -I$(INCLUDES_PATH) -I$(LIBFT_PATH)/$(INCLUDES_PATH)
CFLAGS		= -Wall -Wextra $(INCLUDES) -g
AR			= ar crs
RM			= rm -f
MKDIR-P		= mkdir -p

all: ${NAME}

$(BUILD_PATH):
	$(MKDIR-P) $(BUILD_PATH)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(BUILD_PATH) $(OBJS)
	@${MAKE} -C $(LIBFT_PATH)
	@${CC} ${CFLAGS} ${OBJS} $(LIBFT_PATH)/$(LIBFT) -o ${NAME}

clean: 
	@${MAKE} -C $(LIBFT_PATH) fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

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
