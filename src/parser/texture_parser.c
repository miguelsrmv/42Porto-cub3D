/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:13:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/15 11:12:42 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Fills map_data depending on the starting characters of line
//// Will exit if duplicate data is found
void	check_wall_texture(char **line_as_tab,
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
		exit_cub3(*map_data, REPEATED_ERROR_MSG);
	}
	ft_free_tabs((void **)line_as_tab);
}

/// @brief Checks if textures exist, are .xpm, are readable
//// Will exit in case they're a dir too!
void	check_texture_files(t_map_data **map_data)
{
	int		file_fd;
	int		i;
	char	*textures[4];
	char	*buffer[1];

	textures[0] = (*map_data)->north_texture;
	textures[1] = (*map_data)->south_texture;
	textures[2] = (*map_data)->west_texture;
	textures[3] = (*map_data)->east_texture;
	i = -1;
	while (++i < 4)
	{
		if (ft_checkextension(textures[i], ".xpm"))
			exit_cub3(*map_data, TEXTURE_WRONG_FORMAT_MSG);
		file_fd = open(textures[i], O_RDONLY);
		if (file_fd == -1)
			exit_cub3(*map_data, TEXTURE_ERROR_MSG);
		if (read(file_fd, buffer, 0) == -1 && errno == EISDIR)
		{
			close(file_fd);
			exit_cub3(*map_data, TEXTURE_ERROR_MSG);
		}
		parse_texture(file_fd);
		close(file_fd);
	}
}

/// @brief Checks inner format of each texture
/// @param texture 
void	parse_texture(int texture_fd)
{
	(void)texture_fd;
	return ;
}
