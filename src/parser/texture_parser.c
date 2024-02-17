/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:13:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/17 13:24:27 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Fills map_data depending on the starting characters of line
void	check_wall_texture(char **line_as_tab,
		t_map_data **map_data)
{
	char	*side;

	side = ft_strdup(line_as_tab[1]);
	if (!side)
		exit_cub3(*map_data, MALLOC_ERROR_MSG);
	if (!ft_strcmp(line_as_tab[0], "NO") && !(*map_data)->north_texture)
		(*map_data)->north_texture = side;
	else if (!ft_strcmp(line_as_tab[0], "SO") && !(*map_data)->south_texture)
		(*map_data)->south_texture = side;
	else if (!ft_strcmp(line_as_tab[0], "WE") && !(*map_data)->west_texture)
		(*map_data)->west_texture = side;
	else if (!ft_strcmp(line_as_tab[0], "EA") && !(*map_data)->east_texture)
		(*map_data)->east_texture = side;
	else
	{
		ft_free_tabs((void **)line_as_tab);
		free(side);
		exit_cub3(*map_data, HEADER_ERROR_MSG);
	}
}
