/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:12:46 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/27 11:44:02 by mde-sa--         ###   ########.fr       */
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
	run_cub3d(&cube);
	clean_map_data(cube.map_data);
	return (EXIT_SUCCESS);
}
