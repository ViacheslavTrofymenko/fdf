/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:48:26 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/07/01 10:44:38 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

# define RED "\033[1;31m"
# define RESET "\033[0m"
# define DEFAULT_WIDTH 1280
# define DEFAULT_HEIGHT 720
# define MAX_WIDTH 5120
# define MAX_HEIGHT 2880
# define THIRTY_DEG 0.523599
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define ZOOM_IN 65451
# define ZOOM_OUT 65453
# define P 112
# define Z_IN 50
# define Z_OUT 49

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
	float	zoom;
	float	z_scale;
	float	depth;
	int		shift_x;
	int		shift_y;
	int		projection;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}		t_fdf;

typedef struct s_coords
{
	float	x;
	float	y;
	float	z;
}	t_coords;

typedef struct s_line_params
{
	t_coords	start;
	t_coords	step;
	t_coords	end;
	int			max;
	int			color;
	t_fdf		*fdf;
}	t_line_params;

int		**allocate_matrix(int width, int height);
void	init_fdf(t_fdf *fdf);
void	free_matrix(int ***matrix, int height);
void	free_str_array(char **arr);
int		parse_point(char *str, int *z, int *color);
int		parse_map(char *filename, t_map *map);
int		is_valid_integer(const char *s);
int		is_valid_hex(const char *s);
int		get_map_height(char *filename);
int		get_map_width(char *filename);
char	**split_by_spaces(char *s);
void	draw_map(t_fdf *fdf);
int		handle_key(int key, t_fdf *fdf);
t_point	create_point(int x, int y, t_fdf *fdf);
int		close_window(t_fdf *fdf);
void	isometric(float *x, float *y, int z);
void	draw_line_buf(t_point a, t_point b, t_fdf *fdf);
int		validate_line_width(char **words, int expected_width, int y);
int		parse_line(char *line, int y, t_map *map);
int		count_lines(char *filename);
int		read_lines(int fd, char **buffer, int height);
void	conic(float *x, float *y, float z, t_fdf *fdf);
void	free_all(t_fdf *fdf);

#endif
