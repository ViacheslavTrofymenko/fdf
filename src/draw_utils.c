/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:04:01 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/29 11:22:23 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= DEFAULT_WIDTH || y < 0 || y >= DEFAULT_HEIGHT)
		return;
	dst = fdf->addr + (y * fdf->line_len + x * (fdf->bpp / 8));
	*(unsigned int *)dst = color;
}

static t_coords	prepare_coordinates(t_point p, t_fdf *fdf, float *z)
{
	t_coords	coord;
	float		cx;
	float		cy;

	cx = (fdf->map->width - 1) / 2.0;
	cy = (fdf->map->height - 1) / 2.0;
	coord.x = (p.x - cx) * fdf->zoom;
	coord.y = (p.y - cy) * fdf->zoom;
	*z = p.z * fdf->z_scale;
	if (fdf->projection == 0)
		isometric(&coord.x, &coord.y, *z);
	coord.x += fdf->shift_x;
	coord.y += fdf->shift_y;
	return (coord);
}

static void	calculate_steps(t_coords a, t_coords b, t_coords *step, int *max)
{
	step->x = b.x - a.x;
	step->y = b.y - a.y;
	if (fabsf(step->x) > fabsf(step->y))
	{
		*max = (int)fabsf(step->x);
	}
	else
	{
		*max = (int)fabsf(step->y);
	}
	if (*max != 0)
	{
		step->x /= *max;
		step->y /= *max;
	}
}

static void	draw_line(t_line_params *params)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	x = params->start.x;
	y = params->start.y;
	while (i <= params->max)
	{
		put_pixel(params->fdf, (int)x, (int)y, params->color);
		x += params->step.x;
		y += params->step.y;
		i++;
	}
}

void	draw_line_buf(t_point a, t_point b, t_fdf *fdf)
{
	float			az;
	float			bz;
	t_coords		start;
	t_coords		end;
	t_coords		step;
	int				max;
	t_line_params	params;

	start = prepare_coordinates(a, fdf, &az);
	end = prepare_coordinates(b, fdf, &bz);
	calculate_steps(start, end, &step, &max);
	params.start = start;
	params.step = step;
	params.max = max;
	params.color = a.color;
	params.fdf = fdf;
	draw_line(&params);
}
