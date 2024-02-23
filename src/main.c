/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:12:46 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/23 19:48:57 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int				file_fd;
	t_map_data		*map_data;

	check_usage(argc, argv);
	file_fd = check_file(argv[1]);
	map_data = check_contents(file_fd);
	run_cub3d(map_data);
	test_map_data(map_data);
	clean_map_data(map_data);
	return (EXIT_SUCCESS);
}
