/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:20:13 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/03/20 14:00:01 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Detects "limit" data on the map; creates leaner map tab without it
//// Then, updates player position after cutting down "fat" data
void	map_cleaner(t_map_data **map_data)
{
//	t_lean_limits	lean_limits;

//	lean_limits = get_lean_limits(map_data);
//	recreate_leaner_tab(map_data, lean_limits);
//	update_starting_position(map_data, lean_limits);
	refill_with_0s(map_data);
}

/// @brief Creates "lean tab", a copy of map_tab without the "fat" data
void	recreate_leaner_tab(t_map_data **map_data, t_lean_limits lean_limits)
{
	char			**lean_map;
	char			**old_map;
	int				index;

	lean_map = (char **)malloc(sizeof(char *)
			* (lean_limits.bottom_limit - lean_limits.top_limit + 2));
	if (!lean_map)
		exit_cub3(*map_data, MALLOC_ERROR_MSG);
	index = 0;
	while (index <= (lean_limits.bottom_limit - lean_limits.top_limit))
	{
		lean_map[index]
			= ft_strndup(&(*map_data)->map_tab
			[index + lean_limits.top_limit][lean_limits.left_limit],
				lean_limits.right_limit - lean_limits.left_limit + 1);
		if (!lean_map[index++])
		{
			ft_free_tabs((void **)lean_map);
			exit_cub3(*map_data, MALLOC_ERROR_MSG);
		}
	}
	lean_map[index] = NULL;
	old_map = (*map_data)->map_tab;
	(*map_data)->map_tab = lean_map;
	ft_free_tabs((void **)old_map);
}

/// @brief Takes out the 'X's and fills them again with '0's
void	refill_with_0s(t_map_data **map_data)
{
	int	x;
	int	y;

	y = 0;
	while ((*map_data)->map_tab[y])
	{
		x = 0;
		while ((*map_data)->map_tab[y][x])
		{
			if ((*map_data)->map_tab[y][x] == 'X')
				((*map_data)->map_tab[y][x] = '0');
			x++;
		}
		y++;
	}
}

/// @brief Updates starting position, as well as character on map
void	update_starting_position(t_map_data **map_data,
			t_lean_limits lean_limits)
{
	((*map_data)->start_pos[0]) -= lean_limits.top_limit;
	((*map_data)->start_pos[1]) -= lean_limits.left_limit;
	((*map_data)->map_tab
		[(*map_data)->start_pos[0]][(*map_data)->start_pos[1]])
		= (*map_data)->cardinal_direction;
}

/// @brief Trims initial and final '\n's, thus checking if there is a map
void	trim_map_buffer(t_map_data **map_data)
{
	int		start;
	int		end;
	char	*leaner_buffer;

	start = 0;
	end = ft_strlen((*map_data)->map_buffer);
	while ((*map_data)->map_buffer[start] == '\n')
		start++;
	if (start == end)
		exit_cub3(*map_data, MAP_MISS_ERROR_MSG);
	while ((*map_data)->map_buffer[end - 1] == '\n')
		end--;
	leaner_buffer = ft_strndup(&(*map_data)->map_buffer[start],
			end - start);
	if (!leaner_buffer)
		exit_cub3(*map_data, MALLOC_ERROR_MSG);
	free((*map_data)->map_buffer);
	(*map_data)->map_buffer = leaner_buffer;
}
