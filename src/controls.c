/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:06 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/28 14:10:41 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key(int key, t_fdf *fdf)
{
	if (key == ESC)
		exit(0);
	if (key == LEFT)
		fdf->shift_x -= 10;
	if (key == RIGHT)
		fdf->shift_x += 10;
	if (key == UP)
		fdf->shift_y -= 10;
	if (key == DOWN)
		fdf->shift_y += 10;
	if (key == ZOOM_IN)
		fdf->zoom += 1;
	if (key == ZOOM_OUT && fdf->zoom > 1)
		fdf->zoom -= 1;
	if (key == P)
		fdf->projection = (fdf->projection + 1) % 3;
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_map(fdf);
	return (0);
}
