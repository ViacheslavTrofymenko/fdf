# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 15:57:21 by vtrofyme          #+#    #+#              #
#    Updated: 2025/06/29 12:37:01 by vtrofyme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

SRC_DIR		= src
OBJ_DIR		= obj

SRC			= $(addprefix $(SRC_DIR)/, main.c parcer.c parcer_utils.c\
				parcer_utils2.c utils.c draw.c controls.c init.c\
				isometric_projection.c close_window.c draw_utils.c)
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
LIBFT_DIR	= libs/libft
MLX_DIR		= libs/minilibx-linux

LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES	= -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(SRC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(INCLUDES) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	make -C $(LIBFT_DIR) clean
	rm -fr $(OBJ_DIR)
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
