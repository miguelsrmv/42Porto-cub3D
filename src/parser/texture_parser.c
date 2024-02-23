/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:13:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/23 17:09:58 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Fills map_data depending on the starting characters of line
enum e_HeaderType	check_wall_texture(char **line_as_tab,
		t_map_data **map_data)
{
	char	*texture_path;

	texture_path = ft_strdup(line_as_tab[1]);
	if (!texture_path)
	{
		ft_free_tabs((void **)line_as_tab);
		exit_cub3(*map_data, MALLOC_ERROR_MSG);
	}
	if (!ft_strcmp(line_as_tab[0], "NO") && !(*map_data)->north_texture)
		(*map_data)->north_texture = texture_path;
	else if (!ft_strcmp(line_as_tab[0], "SO") && !(*map_data)->south_texture)
		(*map_data)->south_texture = texture_path;
	else if (!ft_strcmp(line_as_tab[0], "WE") && !(*map_data)->west_texture)
		(*map_data)->west_texture = texture_path;
	else if (!ft_strcmp(line_as_tab[0], "EA") && !(*map_data)->east_texture)
		(*map_data)->east_texture = texture_path;
	else
	{
		ft_free_tabs((void **)line_as_tab);
		free(texture_path);
		return (INVALID);
	}
	ft_free_tabs((void **)line_as_tab);
	return (VALID_INFO);
}
