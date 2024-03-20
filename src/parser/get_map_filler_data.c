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

/* 
/// @brief  Gets leaner limits from top, bottom, left and right of map
t_lean_limits	get_lean_limits(t_map_data **map_data)
{
	t_lean_limits	lean_limits;

	lean_limits.top_limit = detect_top_limit(map_data);
	lean_limits.bottom_limit = detect_bottom_limit(map_data);
	lean_limits.left_limit = detect_left_limit(map_data, lean_limits);
	lean_limits.right_limit = detect_right_limit(map_data, lean_limits);
	return (lean_limits);
}

/// @brief Detects "starting" y for top of a leaner map
int	detect_top_limit(t_map_data **map_data)
{
	int	y;

	y = (*map_data)->start_pos[0] - 1;
	while (y != -1
		&& ft_strchr((*map_data)->map_tab[y], '1'))
		y--;
	y++;
	return (y);
}

/// @brief Detects "ending" y for bottom of a leaner map
int	detect_bottom_limit(t_map_data **map_data)
{
	int	y;

	y = (*map_data)->start_pos[0] + 1;
	while (y < (*map_data)->map_height
		&& ft_strchr((*map_data)->map_tab[y], '1'))
		y++;
	y--;
	return (y);
}

/// @brief Detects "starting" x for left of a leaner map
int	detect_left_limit(t_map_data **map_data, t_lean_limits lean_limits)
{
	int	x;
	int	y;

	x = (*map_data)->start_pos[1] - 1;
	while (x >= 0)
	{
		y = lean_limits.top_limit;
		while ((*map_data)->map_tab[y][x]
			&& y <= lean_limits.bottom_limit)
		{
			if ((*map_data)->map_tab[y++][x] == '1')
				break ;
			if (y > lean_limits.bottom_limit)
				return (x + 1);
		}
		if (x == 0)
			return (x);
		x--;
	}
	return (x);
}

/// @brief Detects "ending" x for right of a leaner map
int	detect_right_limit(t_map_data **map_data, t_lean_limits lean_limits)
{
	int	x;
	int	y;

	x = (*map_data)->start_pos[1] + 1;
	while (x < (*map_data)->map_width)
	{
		y = lean_limits.bottom_limit;
		while ((*map_data)->map_tab[y][x]
			&& y > lean_limits.top_limit)
		{
			if ((*map_data)->map_tab[y--][x] == '1')
				break ;
			if (y <= lean_limits.top_limit)
				return (x - 1);
		}
		if (x == (*map_data)->map_width - 1)
			return (x);
		x++;
	}
	return (x);
}
 */