/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:13:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/23 14:31:25 by mde-sa--         ###   ########.fr       */
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

/// @brief 				Checks if textures exist and are usable
/// @param map_data		Map data struct
enum e_HeaderType	check_texture_files(t_map_data **map_data)
{
	int		file_fd;
	int		i;
	char	*textures[4];

	textures[0] = (*map_data)->north_texture;
	textures[1] = (*map_data)->south_texture;
	textures[2] = (*map_data)->west_texture;
	textures[3] = (*map_data)->east_texture;
	i = 0;
	while (i < 4)
	{
		file_fd = open(textures[i], O_RDONLY);
		if (file_fd == -1)
			exit_cub3(*map_data, TEXTURE_ERROR_MSG);
		close(file_fd);
		i++;
	}
	return (VALID_INFO);
}
