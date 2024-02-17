/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:13:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/17 13:17:42 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Includes
# include "../src/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>

// Defines
/// Error messages
# define OPEN_ERROR_MSG "Error\nProblem opening file"
# define USAGE_ERROR_MSG "Error\nUsage: \"./cube3D map_file.cub.\"\n"
# define MALLOC_ERROR_MSG "Error\nMalloc error.\n"
# define HEADER_ERROR_MSG "Error\nInvalid header.\n"
# define OTHER_ERROR_MSG "Error\nUnspecified error.\n"

// enums
enum e_ExitStatus {
	SUCCESS,
	INVALID_USAGE,
	INVALID_FORMAT,
	INVALID_FILE,
	INVALID_MAP,
	MALLOC_ERROR,
};

enum e_HeaderType {
	VALID_INFO,
	EMPTY_LINE,
	INVALID,
};

// Structs
typedef struct s_map_data
{
	int			file_fd;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			floor_color[3];
	int			ceiling_color[3];
}		t_map_data;

// Function declarations
/// usage_check.c
void				check_usage(int argc, char **argv);
int					check_file(char *file);

/// file_parser.c
t_map_data			*check_contents(int file_fd);
void				initialize_map_data(t_map_data **map_data,
						int file_fd);

/// header_parser.c
void				check_header(t_map_data **map_data);
enum e_HeaderType	check_line(char *line, t_map_data **map_data);
enum e_HeaderType	check_tab_format(char **line_as_tab,
						t_map_data **map_data);
enum e_HeaderType	check_texture_permissions(t_map_data **map_data);
enum e_HeaderType	check_colour_values(t_map_data **map_data);

/// texture_parser.c
void				check_wall_texture(char **line_as_tab,
						t_map_data **map_data);

/// colour_parser.c
void				check_floor_ceiling_texture(char **line_as_tab,
						t_map_data **map_data);
enum e_HeaderType	check_colours_tab(char **colours,
						t_map_data **map_data);

/// map_parser.c
void				check_map(t_map_data **map_data);

/// run_cub3d.c
void				run_cub3d(t_map_data *map_data);

/// clean_memory.c
void				exit_cub3(t_map_data *map_data,
						char *message);
void				clean_map_data(t_map_data *map_data);

#endif