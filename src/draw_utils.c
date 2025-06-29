/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:04:01 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/29 11:39:44 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= DEFAULT_WIDTH || y < 0 || y >= DEFAULT_HEIGHT)
		return ;
	dst = fdf->addr + (y * fdf->line_len + x * (fdf->bpp / 8));
	*(unsigned int *)dst = color;
}

static t_coords	prepare_coordinates(t_point p, t_fdf *fdf)
{
	t_coords	coords;
	float		cx;
	float		cy;

	cx = (fdf->map->width - 1) / 2.0;
	cy = (fdf->map->height - 1) / 2.0;
	coords.x = (p.x - cx) * fdf->zoom;
	coords.y = (p.y - cy) * fdf->zoom;
	coords.z = p.z * fdf->z_scale;
	if (fdf->projection == 0)
		isometric(&coords.x, &coords.y, coords.z);
	coords.x += fdf->shift_x;
	coords.y += fdf->shift_y;
	return (coords);
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
	t_line_params	params;

	params.start = prepare_coordinates(a, fdf);
	params.end = prepare_coordinates(b, fdf);
	calculate_steps(params.start, params.end, &params.step, &params.max);
	params.color = a.color;
	params.fdf = fdf;
	draw_line(&params);
}
