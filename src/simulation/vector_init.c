/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:35:09 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/09 21:19:39 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Starts vector parameters for vector_data
t_vector_data	*initialize_vector_data(t_map_data *map_data)
{
	t_vector_data	*vector_data;

	vector_data = (t_vector_data *)malloc(sizeof(t_vector_data));
	if (!vector_data)
		exit_cub3(map_data, MALLOC_ERROR_MSG);
	vector_data->map_x = map_data->start_pos[X];
	vector_data->map_y = map_data->start_pos[Y];
	vector_data->pos_x = map_data->start_pos[X] + 0.5;
	vector_data->pos_y = map_data->start_pos[Y] + 0.5;
	fill_in_initial_vectors(map_data, vector_data);
	calculate_camera_plane(vector_data, FOV);
	return (vector_data);
}

/// @brief Fills in original vector_info
void	fill_in_initial_vectors(t_map_data *map_data,
			t_vector_data *vector_data)
{
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
	vector_data->delta_dist_x = 0;
	vector_data->delta_dist_y = 0;
}
