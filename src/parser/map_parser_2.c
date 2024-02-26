/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:41:44 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/26 16:37:39 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	fill_in_rest_of_line(t_map_data **map_data, int *x, int *y)
{
	while (*x < (*map_data)->map_width - 1)
	{
		((*map_data)->map_tab)[*y][*x] = '0';
		(*x)++;
	}
	((*map_data)->map_tab)[*y][*x]='\0';
	*x = -1;
	(*y)++;
}

void	define_player_position(t_map_data **map_data, int y, int x, int i)
{
	((*map_data)->map_tab)[y][x] = (*map_data)->map_buffer[i];
	(*map_data)->cardinal_direction = (*map_data)->map_buffer[i];
	((*map_data)->start_pos[0]) = y;
	((*map_data)->start_pos[1]) = x;
}
