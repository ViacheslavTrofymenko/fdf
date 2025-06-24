/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:18 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/24 20:38:58 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_valid_extension(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len < 4)
	{
		ft_printf("%sError: Map name is short.%s\n", RED, RESET);
		return (0);
	}
	if (ft_strncmp(map_name + len - 4, ".fdf", 4) != 0)
	{
		ft_printf("%sError: Not a valid .fdf extension.%s\n", RED, RESET);
		return (0);
	}
	ft_printf("%sGood file extension 👍%s\n", GREEN, RESET);
	return (1);
}

int	close_window(t_fdf *fdf)
{
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->map)
	{
		if (fdf->map->z_matrix)
			free_matrix(fdf->map->z_matrix, fdf->map->height);
		if (fdf->map->color_matrix)
			free_matrix(fdf->map->color_matrix, fdf->map->height);
		free(fdf->map);
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		return (ft_printf("%sError: Wrong number of args.%s\n", RED, RESET));
	if (!is_valid_extension(argv[1]))
		return (1);
	fdf.map = malloc(sizeof(t_map));
	if (!fdf.map)
		return (1);
	if (parse_map(argv[1], fdf.map))
		return (ft_printf("%sError: Failed to parse map..%s\n", RED, RESET));
	fdf.zoom = 20;
	fdf.shift_x = DEFAULT_WIDTH / 2;
	fdf.shift_y = DEFAULT_HEIGHT / 2;
	fdf.angle = THIRTY_DEG;
	fdf.projection = 1;
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT, "FdF");
	fdf.img = mlx_new_image(fdf.mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT);
	fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.line_len, &fdf.endian);
	draw_map(&fdf);
	mlx_key_hook(fdf.win, handle_key, &fdf);
	mlx_hook(fdf.win, 17, 0, close_window, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
