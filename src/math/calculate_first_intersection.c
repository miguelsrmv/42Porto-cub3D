/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_first_intersection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:19:49 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/26 21:03:04 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* /// @brief Checks if the very first wall gets intersected or not
bool	check_first_intersection(t_map_data map_data,
			t_vector_data vector_data, int ray_number, t_target *hit_point)
{
	int		angle;
	double	y_distance;
	double	x_distance;

	angle = int_abs_difference(vector_data.player_angle + ray_angle, 90);
	y_distance = (vector_data.small_delta_dist_y / cos(degrees_to_radians(angle)));	
	x_distance = (vector_data.small_delta_dist_x / cos(degrees_to_radians(90 - angle)));
	if (y_distance < x_distance)
		return (check_first_horizontal_intersection(map_data, vector_data,
			angle, hit_point));
	else if (x_distance < y_distance)
		return (check_first_vertical_intersection(map_data, vector_data,
			angle, hit_point));
	else
		return (check_first_corner_intersection(map_data, vector_data, hit_point));
}

/// @brief Checks first horizontal wall
bool	check_first_horizontal_intersection(t_map_data map_data,
			t_vector_data vector_data, int angle, t_target *hit_point)
{
	double	x_coord;
	double	y_coord;

	x_coord = vector_data.pos_x
		+ vector_data.step_x * tan(degrees_to_radians(angle)) * vector_data.small_delta_dist_x;
	y_coord = vector_data.pos_y + vector_data.step_y * (vector_data.small_delta_dist_y + 1);
	hit_point->x_position = x_coord;
	hit_point->y_position = y_coord;
	if (got_a_hit(x_coord, y_coord, map_data))
	{
		check_wall_side_horizontal(vector_data.step_y, hit_point);
		return (true);
	}
	return (false);
}

/// @brief Checks first vertical wall
bool	check_first_vertical_intersection(t_map_data map_data,
			t_vector_data vector_data, int angle, t_target *hit_point)
{
	double	x_coord;
	double	y_coord;

	x_coord = vector_data.pos_x + vector_data.step_x * (vector_data.small_delta_dist_x + 1);
	y_coord = vector_data.pos_y
		+ vector_data.step_x * tan(degrees_to_radians(90 - angle)) * vector_data.small_delta_dist_y;
	hit_point->x_position = x_coord;
	hit_point->y_position = y_coord;
	if (got_a_hit(x_coord, y_coord, map_data))
	{
		check_wall_side_vertical(vector_data.step_y, hit_point);
		return (true);
	}
	return (false);
}

/// @brief Checks corner case
/// TODO!!!!
bool	check_first_corner_intersection(t_map_data map_data,
			t_vector_data vector_data, t_target *hit_point)
{
	double	x_coord;
	double	y_coord;

	x_coord = 0;
	y_coord = 0;
	if (got_a_hit(x_coord, y_coord, map_data))
	{
		hit_point->x_position = x_coord;
		hit_point->y_position = y_coord;
		return (true);
	}
	(void)vector_data;
	return (false);
}
 */