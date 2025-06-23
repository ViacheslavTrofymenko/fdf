/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:41:18 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/23 13:54:50 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_valid_extension(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len < 4)
	{
		ft_printf("%sError:\nMap name is short.%s\n", RED, RESET);
		return (0);
	}
	if (ft_strncmp(map_name + len - 4, ".fdf", 4) != 0)
	{
		ft_printf("%sError:\nNot a valid .fdf extension.%s\n", RED, RESET);
		return (0);
	}
	ft_printf("%sGood file extension👍%s\n", GREEN, RESET);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (ft_printf("%sError:\nWrong number of args.%s\n", RED, RESET));
	if (!is_valid_extension(argv[1]))
		return (1);
	if (!parse_map(argv[1], &map))
		return (ft_printf("%sError:\nFailed to parse map..%s\n", RED, RESET));
	ft_printf("%sMap parsed successfully!%s\n", GREEN, RESET);
	free_matrix(map.z_matrix, map.height);
	free_matrix(map.color_matrix, map.height);
	return (0);
}
