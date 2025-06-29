/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:18 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/29 11:26:05 by vtrofyme         ###   ########.fr       */
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
		exit(1);
	}
	init_fdf(&fdf);
	draw_map(&fdf);
	mlx_hook(fdf.win, 2, 1, handle_key, &fdf);
	mlx_hook(fdf.win, 17, 0, close_window, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
