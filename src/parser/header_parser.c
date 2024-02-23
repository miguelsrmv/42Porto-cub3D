/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:13:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/23 17:16:02 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief 				Iterates through header to parse data and fill map_data.
void	check_header(t_map_data **map_data)
{
	char				*line;
	int					lines_parsed;
	enum e_HeaderType	line_result;

	lines_parsed = 0;
	while (lines_parsed < 6)
	{
		line = get_next_line((*map_data)->file_fd);
		if (!line)
			exit_cub3(*map_data, HEADER_ERROR_MSG);
		line_result = check_line(line, map_data);
		if (line_result == VALID_INFO)
			lines_parsed++;
		else if (line_result == INVALID)
			exit_cub3(*map_data, HEADER_ERROR_MSG);
	}
	check_texture_files(map_data);
	check_colour_values(map_data);
}

/// @brief	Trims and prepares line to check for relevant info
////// Note: line_as-tab is split by spaces,
////// but maybe it should also be split by \t !
/// @param	line is line read from file
enum e_HeaderType	check_line(char *line, t_map_data **map_data)
{
	char	*trimmed_line;
	char	**line_as_tab;

	if (!line)
		return (EMPTY_LINE);
	trimmed_line = ft_strtrim(line, " \t\n");
	free(line);
	if (!trimmed_line || !ft_strlen(trimmed_line))
	{
		free(trimmed_line);
		return (EMPTY_LINE);
	}
	line_as_tab = ft_split(trimmed_line, ' ');
	free(trimmed_line);
	if (!line_as_tab || !line_as_tab[1])
	{
		ft_free_tabs((void **)line_as_tab);
		return (INVALID);
	}
	return (check_tab_format(line_as_tab, map_data));
}

/// @brief Checks if line has appropriate starting characters
//// If so, sends data to fill in map_data.
/// @param line_as_tab is @param line formatted as a tab (after ft_split)
enum e_HeaderType	check_tab_format(char **line_as_tab,
		t_map_data **map_data)
{
	if ((!ft_strcmp(line_as_tab[0], "NO")
			|| !ft_strcmp(line_as_tab[0], "SO")
			|| !ft_strcmp(line_as_tab[0], "WE")
			|| !ft_strcmp(line_as_tab[0], "EA"))
		&& ft_tablen((void **)line_as_tab) == 2)
		return (check_wall_texture(line_as_tab, map_data));
	else if ((!ft_strcmp(line_as_tab[0], "F")
			|| !ft_strcmp(line_as_tab[0], "C"))
		&& ft_tablen((void **)line_as_tab) < 5)
		return (check_floor_ceiling_texture(line_as_tab, map_data));
	else
		return (INVALID);
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

/// @brief 				Checks if colours are within normal range
void	check_colour_values(t_map_data **map_data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if ((*map_data)->ceiling_color[i] < 0
			|| (*map_data)->ceiling_color[i] > 255)
			exit_cub3(*map_data, COLOUR_ERROR_MSG);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if ((*map_data)->floor_color[i] < 0
			|| (*map_data)->floor_color[i] > 255)
			exit_cub3(*map_data, COLOUR_ERROR_MSG);
		i++;
	}
}
