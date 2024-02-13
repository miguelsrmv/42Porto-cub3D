/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:12:46 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/13 21:42:31 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief 			Parses map to check its validity
/// @param file_fd 	The map file descriptor
/// @return 		Return array / struct / vector with parsed data?
void	check_map(int file_fd)
{
	(void)file_fd;
	return ;
}

/// @brief 		Runs cub3d simulation
/// @param map 	The returned struct from check_map
void	run_cub3d(char *map)
{
	(void)map;
	return ;
}

int	main(int argc, char **argv)
{
	int	file_fd;

	check_usage(argc, argv);
	file_fd = check_file(argv[1]);
	check_map(file_fd);
	run_cub3d(argv[1]);
	return (SUCCESS);
}
