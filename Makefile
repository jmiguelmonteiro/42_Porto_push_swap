# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 17:12:33 by josemigu          #+#    #+#              #
#    Updated: 2025/05/24 11:40:11 by josemigu         ###   ########.fr        #
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
		push_swap.c utils.c checker.c initialization.c \
		operations_basic.c operations_swap.c )

# Objects
OBJS = $(addprefix $(BUILD_PATH)/, $(notdir $(SRCS:.c=.o)))

CC			= cc
INCLUDES	= -I$(INCLUDES_PATH) -I$(LIBFT_PATH)/$(INCLUDES_PATH)
CFLAGS		= -Wall -Wextra -Werror $(INCLUDES) -g
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
