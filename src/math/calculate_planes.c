/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_planes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:14:06 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/25 09:50:05 by mde-sa--         ###   ########.fr       */
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
