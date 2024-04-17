/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_vectors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:14:06 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/17 12:07:57 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Calculates how much a certain ray has to go in a direction for every
/// unit of horizontal or vertical movement. Uses "fabs" to return double.
/// Camera_x goes from -1 to 1, where -1 is far left, 1 is far right
/// and 0 is centre of camera_plane.
void	calculate_deltas(t_vector_data *vector_data, double fov_angle)
{
	double	camera_x;

	camera_x = fov_angle / (FOV / 2);
	vector_data->ray_dir_x = vector_data->vector_dir_x
		+ vector_data->camera_plane_x * camera_x;
	vector_data->ray_dir_y = vector_data->vector_dir_y
		+ vector_data->camera_plane_y * camera_x;
	vector_data->delta_dist_x = fabs(1 / vector_data->ray_dir_x);
	vector_data->delta_dist_y = fabs(1 / vector_data->ray_dir_y);
	vector_data->ray_angle = vector_data->player_angle + fov_angle;
}

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
