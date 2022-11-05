# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 21:28:38 by annstepa          #+#    #+#              #
#    Updated: 2022/07/20 20:13:26 by annstepa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME	=	pipex

# SRCS	=	$(wildcard *.c)

# HEADER	=	pipex.h

# CC		=	gcc

# CFLAGS	=	-Wall -Wextra -Werror

# OBJS	=	${addprefix ,${SRCS: .c=.o}}

# RM		=	rm -rf

# all:		$(NAME)

# $(NAME):	$(OBJS)
# 			${CC} ${CFLAGS} -o $(NAME) $(OBJS)

# %.o: %.c
# 			${CC} ${CFLAGS} -c $< -o {<:.c=.o}

# clean:
# 			rm -f $ (OBJS)
# #			@$ (RM) $(OBJ_M)
# #			@$ (RM) $(OBJ_F)
# #			@$ (RM) $(OBJ_B)
# #			@echo -e "$(YELLOW)objec files deleted!$(DEFAULT)"

# fclean:
# 			rm -f $(OBJS)
# 			rm -f $(NAME)
# #					@$(RM) $(NAME)
# #					@echo -e "$(RED)all deleted!$(DEFAULT)"

# re:			fclean all

# .PHONY:		all clean fclean re


NAME = pipex

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
	cc $(OBJS) $(FLAGS) -o $(NAME)

all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
