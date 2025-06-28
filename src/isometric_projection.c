/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrofyme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:12:05 by vtrofyme          #+#    #+#             */
/*   Updated: 2025/06/26 14:14:50 by vtrofyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void isometric(int *x, int *y, int z, double angle)
{
	int	prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(angle);
	*y = (prev_x + prev_y) * sin(angle) - z;
}
