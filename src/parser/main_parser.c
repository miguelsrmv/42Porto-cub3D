/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:54:14 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/09 12:34:17 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief 			Initializes map_data and parses file to check validity
/// @return 		Return map_data with parsed data
t_map_data	*check_contents(int file_fd, char *map_path)
{
	t_map_data	*map_data;

	map_data = NULL;
	initialize_map_data(&map_data, file_fd);
	check_header(&map_data);
	check_map(&map_data);
	get_window_title(map_path, map_data);
	return (map_data);
}

/// @brief 					Declares and initializes struct t_map_data
void	initialize_map_data(t_map_data **map_data, int file_fd)
{
	*map_data = (t_map_data *)ft_calloc(1, sizeof(t_map_data));
	if (!(*map_data))
	{
		close(file_fd);
		ft_fprintf(STDERR_FILENO, "Error\n");
		perror(MALLOC_ERROR_MSG);
		exit(MALLOC_ERROR);
	}
	(*map_data)->file_fd = file_fd;
	(*map_data)->start_pos[0] = -1;
	(*map_data)->start_pos[1] = -1;
}

/// @brief Gets title for mlx window
/// Format "Cub3d : [map_name]" (without end .cub)
void	get_window_title(char *map_path, t_map_data *map_data)
{
	char	*map_name;
	char	*window_title;
	int		start_pos;

	start_pos = ft_strrchr(map_path, '/') - map_path + 1;
	map_name = ft_strndup(&map_path[start_pos],
			ft_strlen(&map_path[start_pos]) - 4);
	if (!map_name)
		exit_cub3(map_data, MALLOC_ERROR_MSG);
	window_title = ft_strjoin("Cub3d : ", map_name);
	if (!window_title)
	{
		free(map_name);
		exit_cub3(map_data, MALLOC_ERROR_MSG);
	}
	free(map_name);
	map_data->window_title = window_title;
}
