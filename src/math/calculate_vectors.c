/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_vectors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:14:06 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/18 13:59:35 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Calculates angle of the player's central vector
void	calculate_player_angle(t_vector_data *vector_data)
{
	vector_data->player_angle
		= radians_to_degrees(atan2
			(vector_data->vector_dir_y, vector_data->vector_dir_x));
}

/// @brief Calculates camera's plane, given the players' central ray
void	calculate_camera_plane(t_vector_data *vector_data)
{
	double	fov_rad;
	double	player_angle_rads;
	double	camera_plane_x_rads;
	double	camera_plane_y_rads;

	fov_rad = degrees_to_radians(FOV);
	player_angle_rads = degrees_to_radians(vector_data->player_angle);
	camera_plane_x_rads = sin(player_angle_rads) * fov_rad;
	camera_plane_y_rads = cos(player_angle_rads) * fov_rad;
	vector_data->camera_plane_x = -radians_to_degrees(camera_plane_x_rads);
	vector_data->camera_plane_y = radians_to_degrees(camera_plane_y_rads);
}

/// @brief Camera_target goes from -1 to 1, where -1 is far left, 1 is far right
/// and 0 is centre of camera_plane. Each ray starts from the main direction
/// and then adds its deviation on the camera plane. 
/// Ray_angle is player angles' + each ray's deviation.
/// After that, we calculate the deltas for each ray.
void	calculate_deltas(t_vector_data *vector_data, double fov_angle)
{
	double	camera_target;

	camera_target = fov_angle / (FOV / 2);
	vector_data->ray_dir_x = vector_data->vector_dir_x
		+ vector_data->camera_plane_x * camera_target;
	vector_data->ray_dir_y = vector_data->vector_dir_y
		+ vector_data->camera_plane_y * camera_target;
	vector_data->ray_angle = vector_data->player_angle + fov_angle;
	calculate_big_delta(vector_data);
	calculate_small_delta(vector_data);
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

/// @brief Calculates how much a certain ray has to go in a direction
/// to hit the very first tile.
/// Delta_small_dist_x and y are "DBL_MAX" (similar to infinity) if undefined
void	calculate_small_delta(t_vector_data *vector_data)
{
	if (vector_data->ray_dir_x == 0)
		vector_data->small_delta_dist_x = DBL_MAX;
	else
		vector_data->delta_dist_x = fabs(1 / vector_data->ray_dir_x);
	if (vector_data->ray_dir_y == 0)
		vector_data->small_delta_dist_y = DBL_MAX;
	else
		vector_data->delta_dist_y = fabs(1 / vector_data->ray_dir_y);
}
