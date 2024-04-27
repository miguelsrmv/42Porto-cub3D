/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:54:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/27 11:50:41 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief 		Runs cub3d simulation. Starts mlx shenanigans.
void	run_cub3d(t_cube	*cube)
{
	t_vector_data	vector_data;

	initialize_mlx(cube);
	initialize_vector_data(&vector_data, cube->map_data, cube);
	mlx_loop_hook(cube->mlx, render_image, cube);
	mlx_hook(cube->mlx_window, 2, 1L << 0, key_hook, cube);
	// mlx_hooks
	mlx_loop(cube->mlx);
	clean_mlx(cube->mlx, cube->mlx_window, (cube->image.img));
}

/// @brief Starts vector parameters for vector_data
void	initialize_vector_data(t_vector_data *vector_data, t_map_data *map_data, t_cube *cube)
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
/*  	vector_data->ray_dir_x = 0;
	vector_data->ray_dir_y = 0; */
 	vector_data->delta_dist_x = 0;
	vector_data->delta_dist_y = 0;
 /* 	vector_data->small_delta_dist_x = 0;
	vector_data->small_delta_dist_y = 0;
 	vector_data->step_x = 0;
	vector_data->step_y = 0; */
	calculate_camera_plane(vector_data);
	cube->vector_data = vector_data;
}

void	initialize_mlx(t_cube *cube)
{
	void			*mlx;
	void			*mlx_window;
	t_mlx_img		image;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	image.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	cube->mlx = mlx;
	cube->mlx_window = mlx_window;
	cube->image = image;
}

int	render_image(t_cube *cube)
{
	create_image(*(cube->map_data), cube->vector_data, &(cube->image));
	mlx_put_image_to_window(cube->mlx, cube->mlx_window, cube->image.img, 0, 0);
	return (0);
}
