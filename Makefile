# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/12 16:09:08 by jhor              #+#    #+#              #
#    Updated: 2025/12/12 16:10:23 by jhor             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g3 -Wall -Werror -Wextra
NAME = philosopher
RM = rm -f

SRC = main.c ft_atol.c

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
		@$(CC) $(CFLAGS) -I. $(OBJ) -o $@

all: $(NAME)

%.o : %.c
		  @$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJ)

fclean:	clean
		@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re