/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:41:44 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/03/20 18:21:55 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Creates a map_tab given map_height and map_width
void	create_map_tab(t_map_data **map_data)
{
	int	i;

	(*map_data)->map_tab
		= (char **)malloc(sizeof(char *) * ((*map_data)->map_height + 1));
	if (!((*map_data)->map_tab))
		exit_cub3((*map_data), MALLOC_ERROR_MSG);
	i = 0;
	while (i < (*map_data)->map_height)
	{
		(*map_data)->map_tab[i]
			= (char *)malloc(sizeof(char) * ((*map_data)->map_width + 1));
		if (!((*map_data)->map_tab[i]))
			exit_cub3((*map_data), MALLOC_ERROR_MSG);
		i++;
	}
	(*map_data)->map_tab[(*map_data)->map_height] = NULL;
}

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
	if (!(*map_data)->map_buffer[i]
		&& (*map_data)->map_buffer[i - 1] != '\n')
		fill_in_rest_of_line(map_data, &x, &y);
}

/// @brief  Fills lines with "\n" with '0's to make data processing easier
void	fill_in_rest_of_line(t_map_data **map_data, int *x, int *y)
{
	while (*x < (*map_data)->map_width)
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
