/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:13:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/17 13:24:06 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief 				Iterates through header to parse data
void	check_header(t_map_data **map_data)
{
	char				*line;
	int					lines_parsed;
	enum e_HeaderType	line_result;

	lines_parsed = 0;
	while (lines_parsed < 6)
	{
		line = get_next_line((*map_data)->file_fd);
		line_result = check_line(line, map_data);
		if (line_result == VALID_INFO)
			lines_parsed++;
		else if (line_result == INVALID)
		{
			free(line);
			exit_cub3(*map_data, HEADER_ERROR_MSG);
		}
		free(line);
	}
	if (check_texture_permissions(map_data) == INVALID
		|| check_colour_values(map_data) == INVALID)
		exit_cub3(*map_data, HEADER_ERROR_MSG);
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
	if (!trimmed_line || !ft_strlen(trimmed_line))
	{
		free(trimmed_line);
		return (EMPTY_LINE);
	}
	line_as_tab = ft_split(trimmed_line, ' ');
	free(trimmed_line);
	if (!line_as_tab)
		exit_cub3(*map_data, MALLOC_ERROR_MSG);
	else if (!line_as_tab[1] || line_as_tab[2])
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
	if (!ft_strcmp(line_as_tab[0], "NO") || !ft_strcmp(line_as_tab[0], "SO")
		|| !ft_strcmp(line_as_tab[0], "WE") || !ft_strcmp(line_as_tab[0], "EA"))
		check_wall_texture(line_as_tab, map_data);
	else if (!ft_strcmp(line_as_tab[0], "F") || !ft_strcmp(line_as_tab[0], "C"))
		check_floor_ceiling_texture(line_as_tab, map_data);
	else
	{
		ft_free_tabs((void **)line_as_tab);
		exit_cub3(*map_data, HEADER_ERROR_MSG);
	}
	ft_free_tabs((void **)line_as_tab);
	return (VALID_INFO);
}

/// @brief 				Checks if textures exist and are usable
/// @param map_data		Map data struct
enum e_HeaderType	check_texture_permissions(t_map_data **map_data)
{
	(void)map_data;
	return (VALID_INFO);
}

/// @brief 				Checks if colours are within normal range
enum e_HeaderType	check_colour_values(t_map_data **map_data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if ((*map_data)->ceiling_color[i] < 0
			|| (*map_data)->ceiling_color[i] > 255)
			return (INVALID);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if ((*map_data)->floor_color[i] < 0
			|| (*map_data)->floor_color[i] > 255)
			return (INVALID);
		i++;
	}
	return (VALID_INFO);
}
