# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 15:57:21 by vtrofyme          #+#    #+#              #
#    Updated: 2025/06/23 19:21:45 by vtrofyme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

SRC_DIR		= src
SRC			= $(addprefix $(SRC_DIR)/, main.c parcer.c utils.c)
OBJ			= $(SRC:.c=.o)
CC 			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFT_DIR	= libft
MLX_DIR		= ../minilibx-linux

LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES	= -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(SRC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(INCLUDES) -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
