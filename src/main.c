/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:12:46 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/13 19:05:28 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Check proper usage at Command Line Interface, exits if inappropriate
void	check_usage(int argc, char **argv)
{
	if (argc != 2)
		exit(INVALID_USAGE);
	else if (ft_checkextension(argv[1], ".cub"))
		exit(INVALID_FILE_TYPE);
}

/// @brief Check if file exists, permissions, and if it's not a directory
/// @param file The input file
void	check_file(char *file)
{
	(void)file;
	return ;
}

/// @brief Parses map to check its validity.
/// @param map The input map
/// @return Return array / struct / vector with parsed data?
void	check_map(char *map)
{
	(void)map;
	return ;
}

/// @brief Runs cub3d simulation
/// @param map The return value of check_map
void	run_cub3d(char *map)
{
	(void)map;
	return ;
}

int	main(int argc, char **argv)
{
	check_usage(argc, argv);
	check_file(argv[1]);
	check_map(argv[1]);
	run_cub3d(argv[1]);
	return (SUCCESS);
}
