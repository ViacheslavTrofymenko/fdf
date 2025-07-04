/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:18 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/07/02 11:13:54 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

static void	hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 1, handle_key, fdf);
	mlx_hook(fdf->win, 4, 1L << 2, mouse_press, fdf);
	mlx_hook(fdf->win, 5, 1L << 3, mouse_release, fdf);
	mlx_hook(fdf->win, 6, 1L << 6, mouse_move, fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
	get_next_line(-5);
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
		ft_printf("%sError: Failed to allocate memory.%s\n", RED, RESET);
		return (1);
	}
	if (parse_map(argv[1], fdf.map))
	{
		ft_printf("%sError: Failed to parse map.%s\n", RED, RESET);
		free(fdf.map);
		get_next_line(-5);
		exit(1);
	}
	init_fdf(&fdf);
	draw_map(&fdf);
	hooks(&fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
