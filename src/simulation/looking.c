/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:55:13 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/29 18:33:15 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Looks ROTATE_SPEED angles (radians) to the left
void	turn_left(t_vector_data *vector_data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vector_data->vector_dir_x;
	old_plane_x = vector_data->camera_plane_x;
	vector_data->vector_dir_x
		= vector_data->vector_dir_x * cos(-ROTATE_SPEED)
		- vector_data->vector_dir_y * sin(-ROTATE_SPEED);
	vector_data->vector_dir_y
		= old_dir_x * sin(-ROTATE_SPEED)
		+ vector_data->vector_dir_y * cos(-ROTATE_SPEED);
	vector_data->camera_plane_x
		= vector_data->camera_plane_x * cos(-ROTATE_SPEED)
		- vector_data->camera_plane_y * sin(-ROTATE_SPEED);
	vector_data->camera_plane_y
		= old_plane_x * sin(-ROTATE_SPEED)
		+ vector_data->camera_plane_y * cos(-ROTATE_SPEED);
	printf("Position after movement:\n");
	print_vector_data(vector_data);
}

/// @brief Looks ROTATE_SPEED angles (radians) to the right
void	turn_right(t_vector_data *vector_data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vector_data->vector_dir_x;
	old_plane_x = vector_data->camera_plane_x;
	vector_data->vector_dir_x
		= vector_data->vector_dir_x * cos(ROTATE_SPEED)
		- vector_data->vector_dir_y * sin(ROTATE_SPEED);
	vector_data->vector_dir_y
		= old_dir_x * sin(ROTATE_SPEED)
		+ vector_data->vector_dir_y * cos(ROTATE_SPEED);
	vector_data->camera_plane_x
		= vector_data->camera_plane_x * cos(ROTATE_SPEED)
		- vector_data->camera_plane_y * sin(ROTATE_SPEED);
	vector_data->camera_plane_y
		= old_plane_x * sin(ROTATE_SPEED)
		+ vector_data->camera_plane_y * cos(ROTATE_SPEED);
	printf("Position after movement:\n");
	print_vector_data(vector_data);
}
