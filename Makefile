# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 21:05:17 by nfurlani          #+#    #+#              #
#    Updated: 2023/05/12 18:17:52 by nfurlani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	= server
CLIENT	= client
SERVER_B= server_bonus
CLIENT_B= client_bonus
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
PRINTF	= ./Printf
LIBFT	= ./Libft

SRCS_SERVER	= server.c \

SRCS_CLIENT = client.c \

OBJS_SERVER	= $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

SRCS_SERVER_BONUS	= server_bonus.c \

SRCS_CLIENT_BONUS = client_bonus.c \

OBJS_SERVER_BONUS	= $(SRCS_SERVER_BONUS:.c=.o)

OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

all:	lib $(SERVER) $(CLIENT)
 
$(NAME): all

lib:
		@$(MAKE) -C $(PRINTF)
		@$(MAKE) -C $(LIBFT)

%.o: %.c
		@$(CC) $(FLAGS) -o $@ -c $<

$(SERVER): $(OBJS_SERVER)
		$(CC) $(FLAGS) $(PRINTF)/libftprintf.a $(OBJS_SERVER) -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT)
		$(CC) $(FLAGS) $(LIBFT)/libft.a $(OBJS_CLIENT) -o $(CLIENT)

bonus: $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
		$(MAKE) -C $(LIBFT)
		$(MAKE) -C $(PRINTF)
		$(CC) $(FLAGS) $(PRINTF)/libftprintf.a $(OBJS_SERVER_BONUS) -o $(SERVER_B)
		$(CC) $(FLAGS) $(LIBFT)/libft.a $(OBJS_CLIENT_BONUS) -o $(CLIENT_B)

clean:
		@rm -f $(OBJS_SERVER)
		@rm -f $(OBJS_SERVER_BONUS)
		@rm -f $(OBJS_CLIENT)
		@rm -f $(OBJS_CLIENT_BONUS)
		@$(MAKE) -C $(PRINTF) clean
		@$(MAKE) -C $(LIBFT) clean

fclean: clean
		@rm -f $(SERVER)
		@rm -f $(CLIENT)
		@rm -f $(SERVER_B)
		@rm -f $(CLIENT_B)
		@$(MAKE) -C $(PRINTF) fclean
		@$(MAKE) -C $(LIBFT) fclean

re: clean all

.PHONY: all, clean, fclean, re, printf, libft