/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:43:23 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/07/02 11:16:57 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	rotate_x(float *y, float *z, float angle)
{
	float	prev_y;

	prev_y = *y;
	*y = prev_y * cos(angle) - *z * sin(angle);
	*z = prev_y * sin(angle) + *z * cos(angle);
}

static void	rotate_y(float *x, float *z, float angle)
{
	float	prev_x;

	prev_x = *x;
	*x = prev_x * cos(angle) + *z * sin(angle);
	*z = -prev_x * sin(angle) + *z * cos(angle);
}

static void	rotate_z(float *x, float *y, float angle)
{
	float	prev_x;

	prev_x = *x;
	*x = prev_x * cos(angle) - *y * sin(angle);
	*y = prev_x * sin(angle) + *y * cos(angle);
}

void	apply_rotation(t_fdf *fdf, float *x, float *y, float *z)
{
	rotate_x(y, z, fdf->angle_x);
	rotate_y(x, z, fdf->angle_y);
	rotate_z(x, y, fdf->angle_z);
}
