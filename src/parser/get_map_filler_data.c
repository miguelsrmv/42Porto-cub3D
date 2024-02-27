/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_filler_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:30:33 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/27 18:42:51 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief  Gets indexes to be removed from top, bottom, left and right of map
t_filler_data	get_filler_data(t_map_data **map_data)
{
	t_filler_data	filler_data;

	filler_data.top_filler = detect_top_filler(map_data);
	filler_data.bottom_filler = detect_bottom_filler(map_data);
	filler_data.left_filler = detect_left_filler(map_data, filler_data);
	filler_data.right_filler = detect_right_filler(map_data, filler_data);
	return (filler_data);
}

/// @brief Detects "filler" data on top of the map
int	detect_top_filler(t_map_data **map_data)
{
	int	index;

	index = 0;
	while (!ft_strchr((*map_data)->map_tab[index], '1'))
		index++;
	return (index);
}

/// @brief Detects "filler" data on bottom of the map
int	detect_bottom_filler(t_map_data **map_data)
{
	int	index;

	index = (*map_data)->map_height - 1;
	while (!ft_strchr((*map_data)->map_tab[index], '1'))
		index--;
	return (index);
}

/// @brief Detects "filler" data on left of the map
int	detect_left_filler(t_map_data **map_data, t_filler_data filler_data)
{
	int	index;
	int	starting_top_position;

	index = 0;
	starting_top_position = filler_data.top_filler;
	while ((*map_data)->map_tab[filler_data.top_filler])
	{
		if ((*map_data)->map_tab[filler_data.top_filler][index] == '1')
			break ;
		else
			filler_data.top_filler++;
		if (filler_data.top_filler > filler_data.bottom_filler)
		{
			filler_data.top_filler = starting_top_position;
			index++;
		}
	}
	return (index);
}

/// @brief Detects "filler" data on right of the map
int	detect_right_filler(t_map_data **map_data, t_filler_data filler_data)
{
	int	index;
	int	starting_top_position;

	index = (*map_data)->map_width - 2;
	starting_top_position = filler_data.top_filler;
	while ((*map_data)->map_tab[filler_data.top_filler])
	{
		if ((*map_data)->map_tab[filler_data.top_filler][index] == '1')
			break ;
		else
			filler_data.top_filler++;
		if (filler_data.top_filler > filler_data.bottom_filler)
		{
			filler_data.top_filler = starting_top_position;
			index--;
		}
	}
	return (index);
}
