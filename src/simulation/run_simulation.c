/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:24:27 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/11 21:29:43 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Runs simulation on cube
void	run_simulation(t_map_data *map_data, t_mlx_img *img)
{
	t_vector_data	vector_data;

	initialize_vector_data(&vector_data, map_data);
	// Very first image, with vectors' data pos_x and pos_y
	create_image(*map_data, vector_data, img);
/* 	
	Endless loop that will run as key_hooks update vectors_data's pos_x and pos_y
	while (true)
	{
		#1 delete_previously_created_image
		#2 create_image (with now-updated vectors_data pos_x and pos_y)
		#3 mlx_put_image_to_window
	} */
	(void)img;
	return ;
}

/// @brief Starts vector parameters for vector_data
void	initialize_vector_data(t_vector_data *vector_data, t_map_data *map_data)
{
	vector_data->pos_x = (double)map_data->start_pos[1];
	vector_data->pos_y = (double)map_data->start_pos[0];
	if (map_data->cardinal_direction == 'N')
	{
		vector_data->vector_dir_x = 0;
		vector_data->vector_dir_y = 1;
	}
	else if (map_data->cardinal_direction == 'E')
	{
		vector_data->vector_dir_x = 1;
		vector_data->vector_dir_y = 0;
	}
	else if (map_data->cardinal_direction == 'S')
	{
		vector_data->vector_dir_x = 0;
		vector_data->vector_dir_y = -1;
	}
	else if (map_data->cardinal_direction == 'W')
	{
		vector_data->vector_dir_x = -1;
		vector_data->vector_dir_y = 0;
	}
	vector_data->camera_plane_x = 0;
	vector_data->camera_plane_y = FOV;
}
