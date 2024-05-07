/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:53:00 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/07 14:40:28 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Checks if there's an obstacle within a +- 45º field of
/// (movement_vector_x, movement_vector_y), returning if player collides or not
bool	player_collides(t_map_data *map_data, t_vector_data vector_data,
	double movement_vector_x, double movement_vector_y)
{
	int	ray;

	ray = -1;
	vector_data.vector_dir_x = movement_vector_x;
	vector_data.vector_dir_y = movement_vector_y;
	vector_data.delta_dist_x = 0;
	vector_data.delta_dist_y = 0;
	vector_data.map_x = (int)vector_data.pos_x;
	vector_data.map_y = (int)vector_data.pos_y;
	calculate_camera_plane(&vector_data, HITBOX_FOV);
	while (ray <= 1)
	{
		if (collision_distance(map_data, &vector_data, ray) < WALL_OFFSET)
			return (true);
		ray++;
	}
	return (false);
}

double	collision_distance(t_map_data *map_data, t_vector_data *vector_data, int ray)
{
	double	distance;

	vector_data->ray_dir_x = vector_data->vector_dir_x
		+ vector_data->camera_plane_x * ray;
	vector_data->ray_dir_y = vector_data->vector_dir_y
		+ vector_data->camera_plane_y * ray;
	calculate_small_delta(vector_data);
	calculate_big_delta(vector_data);
	distance = calc_distance_from_wall(*map_data, *vector_data);
	return (distance);
}

double	calc_distance_from_wall(t_map_data map_data, t_vector_data vector_data)
{
	char		hit_vector;
	double		distance;

	while (true)
	{
		if (vector_data.small_delta_dist_x < vector_data.small_delta_dist_y)
		{
			vector_data.small_delta_dist_x += vector_data.delta_dist_x;
			vector_data.map_x += vector_data.step_x;
			hit_vector = 'x';
		}
		else
		{
			vector_data.small_delta_dist_y += vector_data.delta_dist_y;
			vector_data.map_y += vector_data.step_y;
			hit_vector = 'y';
		}
		if (got_a_hit(vector_data.map_x, vector_data.map_y, map_data))
			break;
	}
 	if (hit_vector == 'x')
		distance = (vector_data.small_delta_dist_x - vector_data.delta_dist_x);
	else
		distance = (vector_data.small_delta_dist_y - vector_data.delta_dist_y);
	printf("Found a hit at (%i, %i)\n", vector_data.map_x, vector_data.map_y);
	printf("At distance %f with vector %c\n", distance, hit_vector);
	return (distance);
}
