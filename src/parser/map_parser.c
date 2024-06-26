/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:13:49 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/12 17:46:34 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Checks the map part of the header and creates a valid tab
void	check_map(t_map_data **map_data)
{
	get_map_buffer(map_data);
	trim_map_buffer(map_data);
	get_map_dimensions(map_data);
	check_map_chars(map_data);
	create_map_tab(map_data);
	populate_tab(map_data);
	flood_fill(map_data, (*map_data)->start_pos[0], (*map_data)->start_pos[1]);
	check_limit_overflow(map_data);
	map_cleaner(map_data);
}

/// @brief Gets all the map onto a single char *buffer
void	get_map_buffer(t_map_data **map_data)
{
	char	*map_buffer;
	char	*new_buffer;
	char	*temp;

	map_buffer = ft_strdup("");
	if (!map_buffer)
		exit_cub3(*map_data, MALLOC_ERROR_MSG);
	while (true)
	{
		temp = get_next_line((*map_data)->file_fd);
		if (!temp)
			break ;
		new_buffer = ft_strjoin(map_buffer, temp);
		free(temp);
		if (!new_buffer)
		{
			free(map_buffer);
			exit_cub3(*map_data, MALLOC_ERROR_MSG);
		}
		free(map_buffer);
		map_buffer = new_buffer;
	}
	(*map_data)->map_buffer = map_buffer;
}

/// @brief Trims initial and final '\n's, thus checking if there is a map
void	trim_map_buffer(t_map_data **map_data)
{
	int		start;
	int		end;
	char	*leaner_buffer;

	start = 0;
	end = ft_strlen((*map_data)->map_buffer);
	while ((*map_data)->map_buffer[start] == '\n')
		start++;
	if (start == end)
		exit_cub3(*map_data, MAP_MISS_ERROR_MSG);
	while ((*map_data)->map_buffer[end - 1] == '\n')
		end--;
	leaner_buffer = ft_strndup(&(*map_data)->map_buffer[start],
			end - start);
	if (!leaner_buffer)
		exit_cub3(*map_data, MALLOC_ERROR_MSG);
	free((*map_data)->map_buffer);
	(*map_data)->map_buffer = leaner_buffer;
}

/// @brief Gets height and width of map.
//// For simplicity, empty lines will be given the same width as filled ones
//// In the end, checks if map is at least 3x3
void	get_map_dimensions(t_map_data **map_data)
{
	int		i;
	int		old_newline;

	i = 0;
	old_newline = 0;
	while ((*map_data)->map_buffer[i])
	{
		if ((*map_data)->map_buffer[i] == '\n')
		{
			((*map_data)->map_height)++;
			if ((i - old_newline) > ((*map_data)->map_width))
				((*map_data)->map_width) = (i - old_newline - 1);
			old_newline = i;
		}
		i++;
	}
	if ((*map_data)->map_buffer[i - 1]
		&& (*map_data)->map_buffer[i - 1] != '\n')
		((*map_data)->map_height)++;
	if ((*map_data)->map_width <= 2 || (*map_data)->map_height <= 2)
		exit_cub3(*map_data, MAP_SIZE_ERROR_MSG);
}

/// @brief  Checks if only valid characters are used in the map
//// Also checks if there is exactly only one player position
void	check_map_chars(t_map_data **map_data)
{
	int		i;
	int		start_pos_flag;
	char	c;

	i = 0;
	start_pos_flag = 0;
	while ((*map_data)->map_buffer[i])
	{
		c = (*map_data)->map_buffer[i];
		if (c == ' ' || c == '1' || c == '0' || c == '\n')
			i++;
		else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		{
			if (start_pos_flag)
				exit_cub3((*map_data), POS_ERROR_MSG);
			start_pos_flag++;
			i++;
		}
		else
			exit_cub3((*map_data), MAP_CHAR_ERROR_MSG);
	}
	if (!start_pos_flag)
		exit_cub3(*map_data, NO_START_POS);
}
