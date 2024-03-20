/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_limit_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:30:33 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/03/20 11:41:37 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief  Gets leaner limits from top, bottom, left and right of map
t_lean_limits	get_lean_limits(t_map_data **map_data)
{
	t_lean_limits	lean_limits;
	int				x;
	int				y;

	y = 0;
	lean_limits = get_max_values(map_data);
	while ((*map_data)->map_tab[y])
	{
		x = 0;
		while ((*map_data)->map_tab[y][x])
		{
			if ((*map_data)->map_tab[y][x] == 'X')
				update_lean_limits(&lean_limits, x, y);
			x++;
		}
		y++;
	}
	lean_limits.bottom_limit++;
	lean_limits.top_limit--;
	lean_limits.left_limit--;
	lean_limits.right_limit++;
	return (lean_limits);
}

/// @brief  Initalizes limits to most extreme possible values
t_lean_limits	get_max_values(t_map_data **map_data)
{
	t_lean_limits	max_values;

	max_values.top_limit = (*map_data)->map_height - 1;
	max_values.bottom_limit = 0;
	max_values.left_limit = (*map_data)->map_width - 1;
	max_values.right_limit = 0;
	return (max_values);
}

/// @brief  Gets outermost coordinates for 'X' characters
void	update_lean_limits(t_lean_limits *lean_limits, int x, int y)
{
	if (lean_limits->top_limit > y)
		lean_limits->top_limit = y;
	if (lean_limits->bottom_limit < y)
		lean_limits->bottom_limit = y;
	if (lean_limits->left_limit > x)
		lean_limits->left_limit = x;
	if (lean_limits->right_limit < x)
		lean_limits->right_limit = x;
}
