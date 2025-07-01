/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:05:53 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/07/01 10:44:49 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_matrix(int ***matrix, int height)
{
	int	i;

	if (!matrix || !*matrix)
		return ;
	i = 0;
	while (i < height)
	{
		free((*matrix)[i]);
		i++;
	}
	free(*matrix);
	*matrix = NULL;
}

void	free_str_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	free_fdf_map(t_fdf *fdf)
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

void	free_all(t_fdf *fdf)
{
	if (!fdf)
		return ;

	if (fdf->win && fdf->mlx)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		fdf->win = NULL;
	}
	if (fdf->img && fdf->mlx)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = NULL;
	}
	if (fdf->map)
	{
		free_fdf_map(fdf);
	}

	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
		fdf->mlx = NULL;
	}
}

int	close_window(t_fdf *fdf)
{
	free_all(fdf);
	exit(0);
}
