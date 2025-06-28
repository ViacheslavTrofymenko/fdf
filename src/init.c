/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:04:08 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/28 20:51:38 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT, "FdF");
	fdf->zoom = 20;
	fdf->shift_x = DEFAULT_WIDTH / 2;
	fdf->shift_y = DEFAULT_HEIGHT / 2;
	fdf->projection = 0;
	fdf->img = mlx_new_image(fdf->mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->line_len, &fdf->endian);
	mlx_do_key_autorepeaton(fdf->mlx);
}
