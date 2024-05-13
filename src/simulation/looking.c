/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:55:13 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/13 19:17:55 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Looks ROTATE_SPEED angles (radians) p something to the left
/// Rotation speed depends on distance to target
void	turn_left(t_vector_data *vector_data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rotate_speed;

	rotate_speed
		= -ROTATE_SPEED * (1 + (1 / pow(vector_data->front_distance, 2)));
	old_dir_x = vector_data->vector_dir_x;
	old_plane_x = vector_data->camera_plane_x;
	vector_data->vector_dir_x
		= vector_data->vector_dir_x * cos(rotate_speed)
		- vector_data->vector_dir_y * sin(rotate_speed);
	vector_data->vector_dir_y
		= old_dir_x * sin(rotate_speed)
		+ vector_data->vector_dir_y * cos(rotate_speed);
	vector_data->camera_plane_x
		= vector_data->camera_plane_x * cos(rotate_speed)
		- vector_data->camera_plane_y * sin(rotate_speed);
	vector_data->camera_plane_y
		= old_plane_x * sin(rotate_speed)
		+ vector_data->camera_plane_y * cos(rotate_speed);
}

/// @brief Looks ROTATE_SPEED angles (radians) + something to the right
/// Rotation speed depends on distance to target
void	turn_right(t_vector_data *vector_data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rotate_speed;

	old_dir_x = vector_data->vector_dir_x;
	old_plane_x = vector_data->camera_plane_x;
	rotate_speed
		= ROTATE_SPEED * (1 + (1 / pow(vector_data->front_distance, 2)));
	vector_data->vector_dir_x
		= vector_data->vector_dir_x * cos(rotate_speed)
		- vector_data->vector_dir_y * sin(rotate_speed);
	vector_data->vector_dir_y
		= old_dir_x * sin(rotate_speed)
		+ vector_data->vector_dir_y * cos(rotate_speed);
	vector_data->camera_plane_x
		= vector_data->camera_plane_x * cos(rotate_speed)
		- vector_data->camera_plane_y * sin(rotate_speed);
	vector_data->camera_plane_y
		= old_plane_x * sin(rotate_speed)
		+ vector_data->camera_plane_y * cos(rotate_speed);
}
