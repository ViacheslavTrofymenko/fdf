/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:10 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/29 08:27:38 by vtrofyme         ###   ########.fr       */
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
	float	ax;
	float	ay;
	float	bx;
	float	by;
	float	az;
	float	bz;

	float cx = (fdf->map->width - 1) / 2.0;
	float cy = (fdf->map->height - 1) / 2.0;

	ax = (a.x - cx) * fdf->zoom;
	ay = (a.y - cy) * fdf->zoom;
	bx = (b.x - cx) * fdf->zoom;
	by = (b.y - cy) * fdf->zoom;
	az = a.z * fdf->z_scale;
	bz = b.z * fdf->z_scale;

	if (fdf->projection == 0)
	{
		isometric(&ax, &ay, az);
		isometric(&bx, &by, bz);
	}

	ax += fdf->shift_x;
	ay += fdf->shift_y;
	bx += fdf->shift_x;
	by += fdf->shift_y;

	float x_step = bx - ax;
	float y_step = by - ay;
	int max = fmax(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;

	int i = 0;
	while (i <= max)
	{
		put_pixel(fdf, (int)ax, (int)ay, a.color);
		ax += x_step;
		ay += y_step;
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

