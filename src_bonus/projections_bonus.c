/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:12:05 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/07/01 12:50:26 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	isometric(float *x, float *y, int z)
{
	float	prev_x;
	float	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(THIRTY_DEG);
	*y = (prev_x + prev_y) * sin(THIRTY_DEG) - z;
}

void	conic(float *x, float *y, float z, t_fdf *fdf)
{
	float	depth;
	float	scale;

	depth = fdf->depth;
	if (z + depth + 1 == 0)
		scale = 1.0f;
	else
		scale = depth / (z + depth + 1);
	*x = (*x) * scale;
	*y = (*y) * scale - z * scale;
}
