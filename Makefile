# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 15:57:21 by vtrofyme          #+#    #+#              #
#    Updated: 2025/07/01 09:36:14 by vtrofyme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= fdf
NAME_BONUS			= fdf_bonus

SRC_DIR				= src
OBJ_DIR				= obj
SRC_DIR_BONUS		= src_bonus
OBJ_DIR_BONUS		= obj_bonus

SRC				= $(addprefix $(SRC_DIR)/, main.c parcer.c parcer_utils.c\
				parcer_utils2.c utils.c draw.c controls.c init.c\
				isometric_projection.c close_window.c draw_utils.c)
OBJ				= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_BONUS		= $(addprefix $(SRC_DIR_BONUS)/, main_bonus.c parcer_bonus.c\
				parcer_utils_bonus.c parcer_utils2_bonus.c utils_bonus.c\
				 draw_bonus.c controls_bonus.c init_bonus.c draw_utils_bonus.c\
				projections_bonus.c close_window_bonus.c)
OBJ_BONUS		= $(SRC_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
LIBFT_DIR	= libs/libft
MLX_DIR		= libs/minilibx-linux

LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES	= -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(SRC_DIR) -I$(SRC_DIR_BONUS)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(INCLUDES) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLX) $(INCLUDES) -o $(NAME_BONUS)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	make -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -fr $(OBJ_DIR)
	rm -fr $(OBJ_DIR_BONUS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(MLX_DIR)/libmlx.a
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
