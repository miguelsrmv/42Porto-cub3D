/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:14:06 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/27 10:37:55 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 	normalize_vector(double *x, double *y)
{
    double length;
	
	length = sqrt((*x * *x) + (*y * *y));
    *x /= length;
    *y /= length;
}

/// @brief Calculates camera's plane, given the players' central ray
void	calculate_camera_plane(t_vector_data *vector_data)
{
 	double	desired_length;

	vector_data->camera_plane_x = -vector_data->vector_dir_y;
	vector_data->camera_plane_y = vector_data->vector_dir_x;
	normalize_vector(&vector_data->camera_plane_x, &vector_data->camera_plane_y);
    desired_length = FOV;
    vector_data->camera_plane_x *= desired_length;
    vector_data->camera_plane_y *= desired_length;
}
