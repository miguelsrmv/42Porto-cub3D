/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:54:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/25 15:48:04 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief 		Runs cub3d simulation
//// For now, just creates image
/// @param map 	The returned struct from check_map()
void	run_cub3d(t_map_data	*map_data)
{
	void		*mlx;
	void		*mlx_window;
	t_mlx_img	image;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	image.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	run_simulation(map_data, &image);
	//set_hooks(mlx_window, mlx);
	mlx_loop(mlx);
	clean_mlx(mlx, mlx_window, image.img);
	return ;
}

/// @brief Runs simulation on cube
void	run_simulation(t_map_data *map_data, t_mlx_img *img)
{
	t_vector_data	vector_data;
	t_target		target[SCREEN_WIDTH];

	initialize_vector_data(&vector_data, map_data);
	// Very first image, with vectors' data pos_x and pos_y
	target = create_image(*map_data, &vector_data, img);
/* 	
	Endless loop that will run as key_hooks update vectors_data's values
	while (true)
	{
		#1 delete_previously_created_image
		#2 create_image (with now-updated vector_data)
		#3 mlx_put_image_to_window
	} */
	(void)img;
	return ;
}

/// @brief Starts vector parameters for vector_data
/// Creates player position (depending on TILE_SIZE and starting position,
/// Puts player in middle of its square
/// Also creates the correct vector components, and player initial angle
/// Camera plane is perpendicular to vector_dir.
void	initialize_vector_data(t_vector_data *vector_data, t_map_data *map_data)
{
	vector_data->pos_x = (double)map_data->start_pos[1]
		* TILE_SIZE + TILE_SIZE / 2;
	vector_data->pos_y = (double)map_data->start_pos[0]
		* TILE_SIZE + TILE_SIZE / 2;
	vector_data->vector_dir_x = 0;
	vector_data->vector_dir_y = 0;
	if (map_data->cardinal_direction == 'N')
		vector_data->vector_dir_y = -1;
	else if (map_data->cardinal_direction == 'S')
		vector_data->vector_dir_y = 1;
	else if (map_data->cardinal_direction == 'E')
		vector_data->vector_dir_x = 1;
	else if (map_data->cardinal_direction == 'W')
		vector_data->vector_dir_x = -1;
	calculate_player_angle(vector_data);
	calculate_camera_plane(vector_data);
}
