/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:54:14 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/26 22:37:47 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief 			Initializes map_data and parses file to check validity
/// @param file_fd 	The map file descriptor
/// @return 		Return map_data with parsed data
t_map_data	*check_contents(int file_fd)
{
	t_map_data	*map_data;

	map_data = NULL;
	initialize_map_data(&map_data, file_fd);
	check_header(&map_data);
	check_map(&map_data);
	return (map_data);
}

/// @brief 					Declares and initializes struct t_map_data
/// @param map_data 		Double_pointer struct
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
}
