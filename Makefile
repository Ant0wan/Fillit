# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/24 10:06:44 by aquan             #+#    #+#              #
#    Updated: 2018/12/24 10:53:10 by aquan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

SRCS	=	ft_placerm.c\
			ft_position.c\
			ft_setdot.c\
			ft_stock.c\
			ft_tetri_validity.c\
			issamplevalid.c\
			backtracking.c\
			ft_bzero.c\
			ft_memalloc.c\
			output.c\
			main.c\

OBJS	=	$(SRCS:.c=.o)

LIB		=	./includes

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I $(LIB)

RM		=	rm -rf

CLEAN	=	clean

all		:	$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME)	:	$(OBJS) $(LIB)
			$(CC) $(OBJS) -o $(NAME)
			@echo "Joyeux Noel"
clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
