/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:13:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/26 22:30:56 by mde-sa--         ###   ########.fr       */
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
//// Perror messages
# define FILE_ERROR_MSG "Problem opening file"
# define TEXTURE_ERROR_MSG "Problem opening texture"
# define MALLOC_ERROR_MSG "Malloc error\n"
//// Other errors
# define TEXTURE_WRONG_FORMAT_MSG "Invalid texture format"
# define USAGE_ERROR_MSG "Usage: \"./cube3D map_file.cub\"\n"
# define HEADER_ERROR_MSG "Invalid header\n"
# define COLOUR_ERROR_MSG "Invalid header (colour error)\n"
# define REPEATED_ERROR_MSG "Invalid header (repeated data)\n"
# define MAP_ERROR_MSG "Invalid map\n"
# define POS_ERROR_MSG "Invalid map (starting position)\n"
# define MAP_CHAR_ERROR_MSG "Invalid map (invalid characters)\n"
# define MAP_LIMIT_ERROR_MSG "Invalid map (no closed border)\n"
# define OTHER_ERROR_MSG "Unspecified error\n"

// enums
enum e_ExitStatus
{
	SUCCESS,
	INVALID_USAGE,
	INVALID_FORMAT,
	INVALID_FILE,
	INVALID_TEXTURE,
	INVALID_MAP,
	MALLOC_ERROR,
};

enum e_HeaderType
{
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

	int			map_width;
	int			map_height;
	char		*map_buffer;

	char		**map_tab;
	int			start_pos[2];
	char		cardinal_direction;
}		t_map_data;

// Function declarations
/// main.c
int					main(int argc, char **argv);

/// usage_check.c
void				check_usage(int argc, char **argv);
int					check_file(char *file);

/// main_parser.c
t_map_data			*check_contents(int file_fd);
void				initialize_map_data(t_map_data **map_data,
						int file_fd);

/// header_parser.c
void				check_header(t_map_data **map_data);
enum e_HeaderType	check_line(char *line, t_map_data **map_data);
void				check_tab_format(char **line_as_tab,
						t_map_data **map_data);

/// texture_parser.c
void				check_wall_texture(char **line_as_tab,
						t_map_data **map_data);
void				check_texture_files(t_map_data **map_data);

/// colour_parser.c
void				check_floor_ceiling_texture(char **line_as_tab,
						t_map_data **map_data);
void				unite_colours(char **line_as_tab);
enum e_HeaderType	check_colours_tab(char **colours);
void				fill_in_colours(int *color, char **colours);
void				check_colour_values(t_map_data **map_data);

/// map_parser.c
void				check_map(t_map_data **map_data);
void				get_map_buffer(t_map_data **map_data);
void				check_map_chars(t_map_data **map_data);
void				get_map_dimensions(t_map_data **map_data);
void				create_map_tab(t_map_data **map_data);

/// map_parser_2.c
void				populate_tab(t_map_data **map_data);
void				fill_in_rest_of_line(t_map_data **map_data,
						int *x, int *y);
void				define_player_position(t_map_data **map_data,
						int y, int x, int i);
void				flood_fill(t_map_data **map_data,
						int row, int collumn);
void				check_limit_overflow(t_map_data **map_data);

/// run_cub3d.c
void				run_cub3d(t_map_data *map_data);

/// clean_memory.c
void				exit_cub3(t_map_data *map_data,
						char *message);
void				clean_map_data(t_map_data *map_data);

/// helper_functions.c
void				test_map_data(t_map_data *map_data);
void				test_tab_data(t_map_data *map_data);

#endif