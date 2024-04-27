/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:12:46 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/27 16:03:29 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int				file_fd;
	t_cube			cube;

	check_usage(argc, argv);
	file_fd = check_file(argv[1]);
	cube.map_data = check_contents(file_fd);
	cube.vector_data = initialize_vector_data(cube.map_data);
	run_cub3d(&cube);
	clean_data(cube.map_data, cube.vector_data);
	return (EXIT_SUCCESS);
}
