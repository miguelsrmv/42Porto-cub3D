/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:54:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/27 10:00:22 by mde-sa--         ###   ########.fr       */
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
	run_simulation(map_data, &image, mlx, mlx_window);
	//set_hooks(mlx_window, mlx);
	mlx_loop(mlx);
	clean_mlx(mlx, mlx_window, image.img);
	return ;
}

/// @brief Runs simulation on cube
void	run_simulation(t_map_data *map_data, t_mlx_img *img,
			void *mlx, void *mlx_window)
{
	t_vector_data	vector_data;

	initialize_vector_data(&vector_data, map_data);
	create_image(*map_data, &vector_data, img);
	mlx_put_image_to_window(mlx, mlx_window, img->img, 0, 0);
	// create a "while true loop ?"
	return ;
}

/// @brief Starts vector parameters for vector_data
/// Creates player position (depending on TILE_SIZE and starting position,
/// Puts player in middle of its square
/// Also creates the correct vector components, and player initial angle
/// Camera plane is perpendicular to vector_dir.
void	initialize_vector_data(t_vector_data *vector_data, t_map_data *map_data)
{
	vector_data->map_x = map_data->start_pos[X];
	vector_data->map_y = map_data->start_pos[Y];
	vector_data->pos_x = map_data->start_pos[X];
	vector_data->pos_y = map_data->start_pos[Y];
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
 	vector_data->ray_dir_x = 0;
	vector_data->ray_dir_y = 0;
 	vector_data->delta_dist_x = 0;
	vector_data->delta_dist_y = 0;
 	vector_data->small_delta_dist_x = 0;
	vector_data->small_delta_dist_y = 0;
 	vector_data->step_x = 0;
	vector_data->step_y = 0;
	//calculate_player_angle(vector_data);
	calculate_camera_plane(vector_data);
}
