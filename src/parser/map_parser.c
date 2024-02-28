/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:13:49 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/28 11:04:07 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Checks the map part of the header and creates a valid tab
void	check_map(t_map_data **map_data)
{
	get_map_buffer(map_data);
	check_map_chars(map_data);
	get_map_dimensions(map_data);
	create_map_tab(map_data);
	populate_tab(map_data);
	flood_fill(map_data, (*map_data)->start_pos[0], (*map_data)->start_pos[1]);
	check_limit_overflow(map_data);
	map_cleaner(map_data);
	test_tab_data(*map_data);
}

/// @brief Gets all the map onto a single char * buffer
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

/// @brief  Checks if only valid characters are used in the map
//// Also checks if there is only one player position
void	check_map_chars(t_map_data **map_data)
{
	int	i;
	int	start_pos_flag;

	i = 0;
	start_pos_flag = 0;
	while ((*map_data)->map_buffer[i])
	{
		if ((*map_data)->map_buffer[i] == ' '
			|| (*map_data)->map_buffer[i] == '1'
			|| (*map_data)->map_buffer[i] == '0'
			|| (*map_data)->map_buffer[i] == '\n')
			i++;
		else if ((*map_data)->map_buffer[i] == 'N'
			|| (*map_data)->map_buffer[i] == 'S'
			|| (*map_data)->map_buffer[i] == 'W'
			|| (*map_data)->map_buffer[i] == 'E')
		{
			if (start_pos_flag)
				exit_cub3((*map_data), POS_ERROR_MSG);
			start_pos_flag++;
			i++;
		}
		else
			exit_cub3((*map_data), MAP_CHAR_ERROR_MSG);
	}
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
				((*map_data)->map_width) = (i - old_newline);
			old_newline = i;
		}
		i++;
	}
	if ((*map_data)->map_width <= 2 || (*map_data)->map_height <= 2)
		exit_cub3(*map_data, MAP_ERROR_MSG);
}

/// @brief Creates a map_tab given map_height and map_width
void	create_map_tab(t_map_data **map_data)
{
	int	i;

	(*map_data)->map_tab
		= (char **)malloc(sizeof(char *) * ((*map_data)->map_height + 1));
	if (!((*map_data)->map_tab))
		exit_cub3((*map_data), MALLOC_ERROR_MSG);
	i = 0;
	while (i < (*map_data)->map_height)
	{
		(*map_data)->map_tab[i]
			= (char *)malloc(sizeof(char) * ((*map_data)->map_width + 1));
		if (!((*map_data)->map_tab[i]))
			exit_cub3((*map_data), MALLOC_ERROR_MSG);
		i++;
	}
	(*map_data)->map_tab[i] = NULL;
}
