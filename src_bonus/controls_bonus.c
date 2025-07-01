/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:06 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/07/01 10:46:04 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	addional_keys(int key, t_fdf *fdf)
{
	if (key == LEFT)
		fdf->shift_x -= 10;
	if (key == RIGHT)
		fdf->shift_x += 10;
	if (key == UP)
		fdf->shift_y -= 10;
	if (key == DOWN)
		fdf->shift_y += 10;
}

int	handle_key(int key, t_fdf *fdf)
{
	if (key == ESC)
	{
		free_all(fdf);
		exit(0);
	}
	addional_keys(key, fdf);
	if (key == ZOOM_IN)
		fdf->zoom += 0.5;
	if (key == ZOOM_OUT && fdf->zoom > 1)
		fdf->zoom -= 0.5;
	if (key == P)
		fdf->projection = (fdf->projection + 1) % 3;
	if (key == Z_IN)
		fdf->z_scale += 0.2;
	if (key == Z_OUT)
		fdf->z_scale -= 0.2;
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_map(fdf);
	return (0);
}
