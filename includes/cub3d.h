/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:13:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/29 10:02:30 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Includes
# include "../src/libft/libft.h"
# include <float.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <mlx.h>
# include <math.h>
# include <limits.h>

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
# define MAP_MISS_ERROR_MSG "Invalid map (missing map)\n"
# define MAP_SIZE_ERROR_MSG "Invalid map (map too small)\n"
# define POS_ERROR_MSG "Invalid map (starting position)\n"
# define MAP_CHAR_ERROR_MSG "Invalid map (invalid characters)\n"
# define MAP_LIMIT_ERROR_MSG "Invalid map (no closed border)\n"
# define OTHER_ERROR_MSG "Unspecified error\n"
# define NO_START_POS "No starting position\n"

/// Magic numbers
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define FOV 0.66
# define MOVE_SPEED 1
# define WALL_OFFSET 1
# define ROTATE_SPEED (M_PI / 16)

/// TEMPORARY INTS
# define GREEN 65280
# define RED 16711680
# define BLUE 255
# define WHITE 16777215

/// Keys for minilibx
# define KEY_ESC			65307
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_LEFT_ARROW		65361
# define KEY_RIGHT_ARROW	65363

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

enum e_Coordinates
{
	Y,
	X,
};

enum e_CardinalPoint
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
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

typedef struct s_vector_data
{
	// Player position on the grid
	int			map_x;
	int			map_y;

	// Player position on the grid, considering TILE_SIZE
	int			pos_x;
	int			pos_y;

	// Main direction the player is looking at
	double		vector_dir_x;
	double		vector_dir_y;

	// Direction each ray is pointing at
	double		ray_dir_x;
	double		ray_dir_y;

	// Data for each ray
	/// Delta_dist is for checking each tile at a time
	double		delta_dist_x;
	double		delta_dist_y;
	/// Small_delta_dist is for checking very first tile
	double		small_delta_dist_x;
	double		small_delta_dist_y;
	/// Step represents positive or negative direction
	int			step_x;
	int			step_y;

	// Data regarding camera's plane
	double		camera_plane_x;
	double		camera_plane_y;

	// Offset to allow for being centered on squares
	double		offset_x;
	double		offset_y;
}		t_vector_data;

typedef struct s_mlx_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx_img;

typedef struct s_target
{
	double					x_position;
	double					y_position;
	double					distance;
	int						wall_height;
	int						wall_max_height_pixel;
	int						wall_min_height_pixel;
	enum e_CardinalPoint	wall_facing_direction;
}	t_target;

typedef struct s_lean_limits
{
	int			top_limit;
	int			bottom_limit;
	int			left_limit;
	int			right_limit;
}	t_lean_limits;

typedef struct s_cube
{
	t_map_data		*map_data;
	t_vector_data	*vector_data;
	t_mlx_img		image;
	void			*mlx;
	void			*mlx_window;
}	t_cube;

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
void				check_texture_validity(t_map_data **map_data,
						char *file_path);

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
void				trim_map_buffer(t_map_data **map_data);
void				get_map_dimensions(t_map_data **map_data);
void				check_map_chars(t_map_data **map_data);

/// create_map_tab.c
void				create_map_tab(t_map_data **map_data);
void				populate_tab(t_map_data **map_data);
void				fill_in_rest_of_line(t_map_data **map_data,
						int *x, int *y);
void				define_player_position(t_map_data **map_data,
						int y, int x, int i);		
/// check_map_boundaries.c
void				flood_fill(t_map_data **map_data,
						int row, int collumn);
void				check_limit_overflow(t_map_data **map_data);

/// map_cleaner.c
void				map_cleaner(t_map_data **map_data);
void				recreate_leaner_tab(t_map_data **map_data,
						t_lean_limits lean_limits);
void				update_starting_position(t_map_data **map_data,
						t_lean_limits lean_limits);
void				restore_with_0s(t_map_data **map_data);

/// get_map_lean_limits.c
t_lean_limits		get_lean_limits(t_map_data **map_data);
t_lean_limits		get_max_values(t_map_data **map_data);
void				update_lean_limits(t_lean_limits *lean_limits,
						int x, int y);

/// run_cub3d.c
void				run_cub3d(t_cube *cube);
void				initialize_mlx(t_cube *cube);
t_vector_data		*initialize_vector_data(t_map_data *map_data);
int					render_image(t_cube *cube);


/// create_image.c
void				create_image(t_map_data map_data,
						t_vector_data *vector_data, t_mlx_img *img);
void				draw_background(t_map_data map_data, t_mlx_img *img);
void				draw_obstacles(t_map_data map_data, t_vector_data *vector_data,
						t_mlx_img *img);
t_target			cast_ray(t_map_data map_data, t_vector_data *vector_data, int ray_angle);
void				put_walls_on_image(t_target *target_array, t_mlx_img *img);

/// camera_plane.c
void 				normalize_vector(double *x, double *y);
void				calculate_camera_plane(t_vector_data *vector_data);

/// compute_vector_data.c
void				compute_vector_data(t_vector_data *vector_data, int ray_number);
void				calculate_small_delta(t_vector_data *vector_data);
void				calculate_big_delta(t_vector_data *vector_data);

/// check_intersections.c
void				get_intersection(t_map_data map_data,
						t_vector_data vector_data, t_target *hit_point);
void				check_wall_side_horizontal(int step, t_target *hit_point);
void				check_wall_side_vertical(int step, t_target *hit_point);
void				calc_wall_distance_and_height(t_vector_data vector_data, t_target *hit_point);
bool				got_a_hit(int x, int y, t_map_data map_data);

/// clean_memory.c
void				exit_cub3(t_map_data *map_data,
						char *message);
void				clean_data(t_map_data *map_data, t_vector_data *vector_data);
void				clean_mlx(void	*mlx, void	*mlx_window, void *mlx_img);

/// helper_functions.c
void				test_map_data(t_map_data *map_data);
void				test_tab_data(t_map_data *map_data);
void				print_ray_data(t_target *target_array, int array_index);
void				print_vector_data(t_vector_data *vector);

/// my_pixel_put.c
void   				my_pixel_put(t_mlx_img *img, int x, int y, int color);
int					convert_rgb_to_int(int *RGB);
int					temp_colour(enum e_CardinalPoint direction);

/// key_hooks.c
int					key_hook(int keycode, t_cube *cube);

/// movements.c
void				move_foward(t_map_data *map_data, t_vector_data *vector_data);
void				move_backwards(t_map_data *map_data, t_vector_data *vector_data);
void				move_left(t_map_data *map_data, t_vector_data *vector_data);
void				move_right(t_map_data *map_data, t_vector_data *vector_data);

/// looking.c 
void				turn_left(t_vector_data *vector_data);
void				turn_right(t_vector_data *vector_data);

#endif