/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:04:08 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/30 11:33:26 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_initial_view(t_fdf *fdf)
{
	float	width_zoom;
	float	height_zoom;

	if (fdf->map->width <= 1 || fdf->map->height <= 1)
		return ;
	width_zoom = (DEFAULT_WIDTH / 2.0) / (fdf->map->width - 1);
	height_zoom = (DEFAULT_HEIGHT / 2.0) / (fdf->map->height - 1);
	fdf->zoom = fmin(width_zoom, height_zoom);
	fdf->z_scale = 2.0;
	fdf->depth = 500.0;
	fdf->shift_x = DEFAULT_WIDTH / 2;
	fdf->shift_y = DEFAULT_HEIGHT / 2;
	fdf->projection = 0;
}

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT, "FdF");
	set_initial_view(fdf);
	fdf->img = mlx_new_image(fdf->mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp,
			&fdf->line_len, &fdf->endian);
	mlx_do_key_autorepeaton(fdf->mlx);
}
