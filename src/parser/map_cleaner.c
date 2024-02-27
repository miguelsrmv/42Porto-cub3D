/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:20:13 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/27 18:58:37 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Detects "filler" data on the map; creates leaner map tab without it
//// Then, updates player position after cutting down "fat" data
void	map_cleaner(t_map_data **map_data)
{
	t_filler_data	filler_data;

	filler_data = get_filler_data(map_data);
	recreate_leaner_tab(map_data, filler_data);
	refill_with_0s(map_data);
	update_starting_position(map_data, filler_data);
}

/// @brief Creates "lean tab", a copy of map_tab without the "fat" data
void	recreate_leaner_tab(t_map_data **map_data, t_filler_data filler_data)
{
	char			**lean_map;
	char			**old_map;
	int				index;

	lean_map = (char **)malloc(sizeof(char *)
			* (filler_data.bottom_filler - filler_data.top_filler + 2));
	if (!lean_map)
		exit_cub3(*map_data, MALLOC_ERROR_MSG);
	index = 0;
	while (index <= (filler_data.bottom_filler - filler_data.top_filler))
	{
		lean_map[index]
			= ft_strndup(&(*map_data)->map_tab
			[index + filler_data.top_filler][filler_data.left_filler],
				filler_data.right_filler - filler_data.left_filler + 1);
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

void	update_starting_position(t_map_data **map_data,
			t_filler_data filler_data)
{
	((*map_data)->start_pos[0]) -= filler_data.top_filler;
	((*map_data)->start_pos[1]) -= filler_data.left_filler;
	((*map_data)->map_tab
		[(*map_data)->start_pos[0]][(*map_data)->start_pos[1]])
		= (*map_data)->cardinal_direction;
}
