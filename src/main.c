/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:18 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/28 20:54:24 by vtrofyme         ###   ########.fr       */
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
	return (1);
}
int	close_window(t_fdf *fdf)
{
	if (!fdf)
		return (1);

	if (fdf->img && fdf->mlx)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = NULL;
	}
	if (fdf->win && fdf->mlx)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		fdf->win = NULL;
	}
	if (fdf->map)
	{
		if (fdf->map->z_matrix)
		{
			free_matrix(&fdf->map->z_matrix, fdf->map->height);
			fdf->map->z_matrix = NULL;
		}
		if (fdf->map->color_matrix)
		{
			free_matrix(&fdf->map->color_matrix, fdf->map->height);
			fdf->map->color_matrix = NULL;
		}
		free(fdf->map);
		fdf->map = NULL;
	}
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
		fdf->mlx = NULL;
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
	{
		ft_printf("%sError: Failed to allocate memory for map.%s\n", RED, RESET);
		return (1);
	}
	if (parse_map(argv[1], fdf.map))
	{
		ft_printf("%sError: Failed to parse map.%s\n", RED, RESET);
		exit(1);
	}
	init_fdf(&fdf);
	draw_map(&fdf);
	mlx_hook(fdf.win, 2, 1L<<0, handle_key, &fdf);
	mlx_hook(fdf.win, 17, 0, close_window, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
