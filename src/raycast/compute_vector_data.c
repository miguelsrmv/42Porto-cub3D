/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_vector_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:50:12 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/06 22:32:00 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Camera_target goes from -1 to 1, where -1 is far left, 1 is far right
/// and 0 is centre of camera_plane. Each ray starts from the main direction
/// and then adds its deviation on the camera plane. 
/// Ray_angle is player angles' + each ray's deviation.
/// After that, we calculate the deltas for each ray.
void	compute_vector_data(t_vector_data *vector_data, int ray_number)
{
	double	camera_target;

	camera_target = 2 * ray_number / (double)SCREEN_WIDTH - 1;
	vector_data->ray_dir_x = vector_data->vector_dir_x
		+ vector_data->camera_plane_x * camera_target;
	vector_data->ray_dir_y = vector_data->vector_dir_y
		+ vector_data->camera_plane_y * camera_target;
	calculate_small_delta(vector_data);
	calculate_big_delta(vector_data);
}

/// @brief Calculates how much a certain ray has to go in a direction
/// to hit the very first tile. Also calculates direction of step
void	calculate_small_delta(t_vector_data *vector_data)
{
	if (vector_data->ray_dir_x < 0)
	{
		vector_data->step_x = -1;
		vector_data->small_delta_dist_x = (vector_data->pos_x
				- vector_data->map_x) * vector_data->delta_dist_x;
	}
	else
	{
		vector_data->step_x = 1;
		vector_data->small_delta_dist_x = (vector_data->map_x + 1
				- vector_data->pos_x) * vector_data->delta_dist_x;
	}
	if (vector_data->ray_dir_y < 0)
	{
		vector_data->step_y = -1;
		vector_data->small_delta_dist_y = (vector_data->pos_y
				- vector_data->map_y) * vector_data->delta_dist_y;
	}
	else
	{
		vector_data->step_y = 1;
		vector_data->small_delta_dist_y = (vector_data->map_y + 1
				- vector_data->pos_y) * vector_data->delta_dist_y;
	}
}

/// @brief Calculates how much a certain ray has to go in a direction for every
/// unit of horizontal or vertical movement. Uses "fabs" to return double.
/// Delta_Dist_x and y are "DBL_MAX" (similar to infinity) if undefined
void	calculate_big_delta(t_vector_data *vector_data)
{
	if (vector_data->ray_dir_x == 0)
		vector_data->delta_dist_x = DBL_MAX;
	else
		vector_data->delta_dist_x = fabs(1 / vector_data->ray_dir_x);
	if (vector_data->ray_dir_y == 0)
		vector_data->delta_dist_y = DBL_MAX;
	else
		vector_data->delta_dist_y = fabs(1 / vector_data->ray_dir_y);
}
