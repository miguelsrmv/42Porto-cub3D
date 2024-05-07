/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:14:06 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/07 14:10:00 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Normalize's the vectors' size
void	normalize_vector(double *x, double *y)
{
	double	length;

	length = sqrt((*x * *x) + (*y * *y));
	*x /= length;
	*y /= length;
}

/// @brief Calculates camera's plane, given the players' central ray
void	calculate_camera_plane(t_vector_data *vector_data, double fov_angle)
{
	vector_data->camera_plane_x = -vector_data->vector_dir_y;
	vector_data->camera_plane_y = vector_data->vector_dir_x;
	normalize_vector(&vector_data->camera_plane_x,
		&vector_data->camera_plane_y);
	vector_data->camera_plane_x *= fov_angle;
	vector_data->camera_plane_y *= fov_angle;
}
