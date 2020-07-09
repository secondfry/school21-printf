# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sselusa <sselusa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 22:34:04 by sselusa           #+#    #+#              #
#    Updated: 2019/12/28 16:03:40 by sselusa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	-------------------------------------------------------------------------  #
#		PROJECT      --------------------------------------------------------  #
#	-------------------------------------------------------------------------  #

NAME = libftprintf.a
SHARED = libftprintf.so
BINARY = ft_printf.out

#	-----------------------------------------------------  #
#		SOURCES      ------------------------------------  #
#		HEADERS      ------------------------------------  #
#		OBJECTS      ------------------------------------  #
#	-----------------------------------------------------  #

SRCS_DIR = ./srcs
INCL_DIR = ./includes
LIB = ft_libft.a
LIB_DIR = ./ft_libft
LIB_INCL_DIR = $(LIB_DIR)/includes
OBJS_DIR = ./objects

ALL_SRCS = ft_printf.c gc.c init.c input.c output.c bitflags.c

SRCS = $(addprefix $(SRCS_DIR)/, $(ALL_SRCS))
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)
INCL = $(INCL_DIR)

#	-----------------------------------------------------  #
#		FLAGS        ------------------------------------  #
#	-----------------------------------------------------  #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
DFLAGS = -MMD -MP
IFLAGS = -I $(INCL_DIR) -I $(LIB_INCL_DIR)
LFLAGS = -L $(LIB_DIR) -lft
DEBUG = -g
SO_FLAGS = -shared -fPIC

#	-----------------------------------------------------  #
#		RULES        ------------------------------------  #
#	-----------------------------------------------------  #

.PHONY: all clean fclean re so bin

all:
	@$(MAKE) -s $(LIB_DIR)/$(LIB)
	@$(MAKE) $(NAME)

-include $(DEPS)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@/bin/echo -n "═"
	@$(CC) $(CFLAGS) $(DFLAGS) -c -o $@ $< $(IFLAGS)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@/bin/echo "╣ $(NAME)"

$(LIB_DIR)/$(LIB):
	@$(MAKE) -C $(LIB_DIR)

bin: $(LIB_DIR)/$(LIB)
	$(CC) $(CFLAGS) -o $(BINARY) $(IFLAGS) $(LFLAGS) $(DEBUG) $(SRCS) $(SRCS_DIR)/main.c

sanic: $(LIB_DIR)/$(LIB)
	$(CC) $(CFLAGS) -o $(BINARY) $(IFLAGS) $(LFLAGS) $(DEBUG) $(SRCS) $(SRCS_DIR)/main.c -fsanitize=address

so:
	@$(MAKE) -s $(LIB_DIR)/$(LIB)
	@$(MAKE) $(SHARED)

$(SHARED): $(OBJS)
	@$(CC) -o $(SHARED) $(SO_FLAGS) $(OBJS) $(LFLAGS)
	@/bin/echo "╣ $(SHARED)"

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	@if [ -d "$(OBJS_DIR)" ]; then \
		rm -rf $(OBJS_DIR); \
		/bin/echo "╣ rm ft_printf objects"; \
	fi

fclean: clean
	@$(MAKE) -C $(LIB_DIR) fclean
	@if [ -f "$(NAME)" ]; then \
		rm -rf $(NAME); \
		/bin/echo "╣ rm $(NAME)"; \
	fi
	@if [ -f "$(SHARED)" ]; then \
		rm -rf $(SHARED); \
		/bin/echo "╣ rm $(SHARED)"; \
	fi

re: fclean all
