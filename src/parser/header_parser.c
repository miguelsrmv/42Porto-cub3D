/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:13:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/23 14:32:45 by mde-sa--         ###   ########.fr       */
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
	if (!line_as_tab || !line_as_tab[1] || ft_tablen((void **)line_as_tab) > 2)
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
		return (check_wall_texture(line_as_tab, map_data));
	else if (!ft_strcmp(line_as_tab[0], "F") || !ft_strcmp(line_as_tab[0], "C"))
		return (check_floor_ceiling_texture(line_as_tab, map_data));
	else
		return (INVALID);
}
