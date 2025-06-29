/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:10 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/29 11:22:52 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_right(int x, int y, t_fdf *fdf)
{
	t_point	a;
	t_point	b;

	a.x = x;
	a.y = y;
	a.z = fdf->map->z_matrix[y][x];
	a.color = fdf->map->color_matrix[y][x];
	b = a;
	b.x = x + 1;
	b.z = fdf->map->z_matrix[y][x + 1];
	b.color = fdf->map->color_matrix[y][x + 1];
	draw_line_buf(a, b, fdf);
}

static void	draw_line_down(int x, int y, t_fdf *fdf)
{
	t_point	a;
	t_point	b;

	a.x = x;
	a.y = y;
	a.z = fdf->map->z_matrix[y][x];
	a.color = fdf->map->color_matrix[y][x];
	b = a;
	b.y = y + 1;
	b.z = fdf->map->z_matrix[y + 1][x];
	b.color = fdf->map->color_matrix[y + 1][x];
	draw_line_buf(a, b, fdf);
}

void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	ft_bzero(fdf->addr, DEFAULT_HEIGHT * fdf->line_len);
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
				draw_line_right(x, y, fdf);
			if (y < fdf->map->height - 1)
				draw_line_down(x, y, fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
