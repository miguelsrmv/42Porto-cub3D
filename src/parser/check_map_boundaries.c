/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_boundaries.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:17:06 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/03/20 18:23:03 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief "Flood_fill technique" to check for map limits
void	flood_fill(t_map_data **map_data, int row, int collumn)
{
	if (collumn < 0
		|| row < 0
		|| collumn >= (*map_data)->map_width
		|| row >= (*map_data)->map_height)
		return ;
	if (!((*map_data)->map_tab)[row][collumn]
		|| ((*map_data)->map_tab)[row][collumn] == '1'
		|| ((*map_data)->map_tab)[row][collumn] == 'X')
		return ;
	(*map_data)->map_tab[row][collumn] = 'X';
	flood_fill(map_data, row - 1, collumn);
	flood_fill(map_data, row + 1, collumn);
	flood_fill(map_data, row, collumn - 1);
	flood_fill(map_data, row, collumn + 1);
}

/// @brief Checks if there are Xs in outer borders of map
//// Note: corners don't count?!
void	check_limit_overflow(t_map_data **map_data)
{
	int	row;
	int	collumn;

	row = 0;
	while ((*map_data)->map_tab[row])
	{
		if (row == 0 || row == ((*map_data)->map_height - 1))
		{
			collumn = 1;
			while (collumn < (*map_data)->map_width - 1)
			{
				if (((*map_data)->map_tab[row][collumn++]) == 'X' &&
					collumn != (*map_data)->map_width - 1)
					exit_cub3((*map_data), MAP_LIMIT_ERROR_MSG);
			}
		}
		else
		{
			if ((*map_data)->map_tab[row][0] == 'X'
				|| ((*map_data)->map_tab[row][(*map_data)->map_width - 1])
					== 'X')
				exit_cub3((*map_data), MAP_LIMIT_ERROR_MSG);
		}
		row++;
	}
}
