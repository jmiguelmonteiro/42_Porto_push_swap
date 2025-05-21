# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 17:12:33 by josemigu          #+#    #+#              #
#    Updated: 2025/05/21 18:03:24 by josemigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Paths
SRC_PATH		= src
LIBFT_PATH		= libft
INCLUDES_PATH	= includes
BUILD_PATH		= build

SRCS = $(addprefix $(SRC_PATH)/, \
		push_swap.c)

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
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean: 
	@${MAKE} -C $(LIBFT_PATH) fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
