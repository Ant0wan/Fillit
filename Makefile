# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquan <auqn@student.42.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/24 10:06:44 by aquan             #+#    #+#              #
#    Updated: 2018/12/31 18:25:57 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

SRCS	=	ft_placerm.c\
			ft_position.c\
			ft_setdot.c\
			ft_stock.c\
			ft_map.c\
			ft_tetri_validity.c\
			issamplevalid.c\
			backtracking.c\
			ft_bzero.c\
			ft_memalloc.c\
			output.c\
			main.c\

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

all		:	$(NAME)

%.o		:	%.c
			@$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME)	:	$(OBJS)
			@$(CC) $(OBJS) -o $(NAME)
			@echo "\x1b[32;01mcompilation done\x1b[0m"
clean	:
			@$(RM) $(OBJS) 1>/dev/null
			@echo "\x1b[34;01mclean done\x1b[0m"

fclean	:	clean
			@$(RM) $(NAME) 1>/dev/null
			@echo "\x1b[31;01mfclean done\x1b[0m"

re		:	fclean all
