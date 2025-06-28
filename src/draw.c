/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:10 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/28 10:16:33 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= DEFAULT_WIDTH || y < 0 || y >= DEFAULT_HEIGHT)
		return ;
	dst = fdf->addr + (y * fdf->line_len + x * (fdf->bpp / 8));
	*(unsigned int *)dst = color;
}

static void draw_line_buf(t_point a, t_point b, t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	int		max;
	int		i;

	a.x *= fdf->zoom;
	a.y *= fdf->zoom;
	a.z *= fdf->zoom / 2;
	b.x *= fdf->zoom;
	b.y *= fdf->zoom;
	b.z *= fdf->zoom / 2;

	if (fdf->projection == 0)
	{
		isometric(&a.x, &a.y, a.z, fdf->angle);
		isometric(&b.x, &b.y, b.z, fdf->angle);
	}

	a.x += fdf->shift_x;
	a.y += fdf->shift_y;
	b.x += fdf->shift_x;
	b.y += fdf->shift_y;

	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = fmax(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	i = 0;
	while (i <= max)
	{
		put_pixel(fdf, a.x, a.y, a.color);
		a.x += x_step;
		a.y += y_step;
		i++;
	}
}

void draw_map(t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	a;
	t_point	b;

	ft_bzero(fdf->addr, DEFAULT_HEIGHT * fdf->line_len);

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			a.x = x;
			a.y = y;
			a.z = fdf->map->z_matrix[y][x];
			a.color = fdf->map->color_matrix[y][x];
			if (x < fdf->map->width - 1)
			{
				b = a;
				b.x = x + 1;
				b.z = fdf->map->z_matrix[y][x + 1];
				b.color = fdf->map->color_matrix[y][x + 1];
				draw_line_buf(a, b, fdf);
			}
			if (y < fdf->map->height - 1)
			{
				b = a;
				b.y = y + 1;
				b.z = fdf->map->z_matrix[y + 1][x];
				b.color = fdf->map->color_matrix[y + 1][x];
				draw_line_buf(a, b, fdf);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

