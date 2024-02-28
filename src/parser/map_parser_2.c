/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:41:44 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/28 10:54:11 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Fills tab with data from the buffer
void	populate_tab(t_map_data **map_data)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while ((*map_data)->map_buffer[i])
	{
		if ((*map_data)->map_buffer[i] == '\n')
			fill_in_rest_of_line(map_data, &x, &y);
		else if ((*map_data)->map_buffer[i] == '0'
			|| (*map_data)->map_buffer[i] == '1')
			((*map_data)->map_tab)[y][x] = (*map_data)->map_buffer[i];
		else if ((*map_data)->map_buffer[i] == ' ')
			((*map_data)->map_tab)[y][x] = '0';
		else
			define_player_position(map_data, y, x, i);
		i++;
		x++;
	}
}

/// @brief  Fills lines with "\n" with '0's to make data processing easier
void	fill_in_rest_of_line(t_map_data **map_data, int *x, int *y)
{
	while (*x < (*map_data)->map_width - 1)
	{
		((*map_data)->map_tab)[*y][*x] = '0';
		(*x)++;
	}
	((*map_data)->map_tab)[*y][*x] = '\0';
	*x = -1;
	(*y)++;
}

/// @brief Defines starting position from player
void	define_player_position(t_map_data **map_data, int y, int x, int i)
{
	((*map_data)->map_tab)[y][x] = (*map_data)->map_buffer[i];
	(*map_data)->cardinal_direction = (*map_data)->map_buffer[i];
	((*map_data)->start_pos[0]) = y;
	((*map_data)->start_pos[1]) = x;
}

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
	flood_fill(map_data, row -1, collumn);
	flood_fill(map_data, row +1, collumn);
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
			while ((*map_data)->map_tab[row][collumn])
			{
				if (((*map_data)->map_tab[row][collumn++]) == 'X' &&
					collumn != (*map_data)->map_width - 2)
					exit_cub3((*map_data), MAP_LIMIT_ERROR_MSG);
			}
		}
		else
		{
			if ((*map_data)->map_tab[row][0] == 'X'
				|| ((*map_data)->map_tab[row][(*map_data)->map_width - 2])
					== 'X')
				exit_cub3((*map_data), MAP_LIMIT_ERROR_MSG);
		}
		row++;
	}
}
