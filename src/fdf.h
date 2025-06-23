/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:48:26 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/23 23:04:51 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>

/* color for printing on the screen*/
# define COLOR_WHITE 0xFFFFFF
# define COLOR_BLACK 0x000000
# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_BLUE 0x0000FF
# define COLOR_YELLOW 0xFFFF00
# define COLOR_MAGENTA 0xFF00FF
# define COLOR_CYAN 0x00FFFF
/* Define color macros */
# define GREEN   "\033[1;32m"
# define CYAN    "\033[1;36m"
# define YELLOW  "\033[1;33m"
# define RED     "\033[1;31m"
# define RESET   "\033[0m"
/* Define default size for the windows */
# define DEFAULT_WIDTH 1280
# define DEFAULT_HEIGHT 720
# define MAX_WIDTH 5120
# define MAX_HEIGHT 2880
/* Useful Macros for the angles */
# define PI 3.14159265358979323846

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_point;

typedef struct s_map
{
	int	width;
	int	height;
	int	**z_matrix;
	int	**color_matrix;
}		t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	*map;
	int		zoom;
	int		shift_x;
	int		shift_y;
	int		projection;
	double	angle;
}		t_fdf;

int		**allocate_matrix(int width, int height);
void	free_matrix(int **matrix, int height);
void	free_str_array(char **arr);
int		parse_point(char *str, int *z, int *color);
int		parse_map(char *filename, t_map *map);
int		is_valid_integer(const char *s);
int		is_valid_hex(const char *s);
int		get_map_height(char *filename);
int		get_map_width(char *filename);
char	**split_by_spaces(char *s);

#endif
