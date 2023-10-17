# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 17:52:01 by nfurlani          #+#    #+#              #
#    Updated: 2023/02/10 11:07:35 by nfurlani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_print_base.c ft_print_hex.c ft_printf.c

OBJS		= $(SRCS:.c=.o)

INCL		= includes/libftprintf.h

CFLAGS		= -Wall -Wextra -Werror -I.

RM 			= rm -f

CC			= gcc

all:		$(NAME)

$(NAME):	$(OBJS) $(BONUS_OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:		$(BONUS_OBJS)
			ar rcs $(NAME) $(BONUS_OBJS)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		clean fclean all re
