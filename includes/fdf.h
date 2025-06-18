/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:48:26 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/18 23:57:22 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>

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
	int	**color_matrix:
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

#endif
//https://github.com/ailopez-o/42Barcelona-FdF?tab=readme-ov-file
