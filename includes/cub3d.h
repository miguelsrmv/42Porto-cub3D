/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:13:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/13 21:55:53 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../src/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>


enum e_ExitStatus {
	SUCCESS,
	INVALID_USAGE,
	INVALID_FORMAT,
	INVALID_FILE,
	INVALID_MAP,
};


// usage_check.c
void	check_usage(int argc, char **argv);
int		check_file(char *file);

// map_parser.c
void	check_map(int file_fd);

// run_cub3d.c
void	run_cub3d(char *map);

#endif