/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:19:31 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/05 11:48:49 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Gets first intersection given a ray angle
/// Fills hit_point with that data
void	get_intersection(t_map_data map_data,
			t_vector_data vector_data, t_target *hit_point)
{
	bool		hit_flag;

	hit_flag = false;
	while (!hit_flag)
	{
		if (vector_data.small_delta_dist_x < vector_data.small_delta_dist_y)
		{
			vector_data.small_delta_dist_x += vector_data.delta_dist_x;
			vector_data.map_x += vector_data.step_x;
			check_wall_side_vertical(vector_data.step_x, hit_point);
		}
		else
		{
			vector_data.small_delta_dist_y += vector_data.delta_dist_y;
			vector_data.map_y += vector_data.step_y;
			check_wall_side_horizontal(vector_data.step_y, hit_point);
		}
		if (got_a_hit(vector_data.map_x, vector_data.map_y, map_data))
			hit_flag = true;
	}
	hit_point->x_position = vector_data.map_x;
	hit_point->y_position = vector_data.map_y;
	calc_wall_distance_and_height(vector_data, hit_point);
}

/// @brief Checks if wall was hit from NORTH or SOUTH 
void	check_wall_side_horizontal(int step, t_target *hit_point)
{
	if (step == 1)
		hit_point->wall_facing_direction = NORTH;
	else if (step == -1)
		hit_point->wall_facing_direction = SOUTH;
}

/// @brief Checks if wall was hit from EAST or WEST
void	check_wall_side_vertical(int step, t_target *hit_point)
{
	if (step == 1)
		hit_point->wall_facing_direction = WEST;
	else if (step == -1)
		hit_point->wall_facing_direction = EAST;
}

/// @brief Checks distance and wall height
void	calc_wall_distance_and_height(t_vector_data vector_data,
	t_target *hit_point)
{
	if (hit_point->wall_facing_direction == WEST
		|| hit_point->wall_facing_direction == EAST)
		hit_point->distance
			= vector_data.small_delta_dist_x - vector_data.delta_dist_x;
	else
		hit_point->distance
			= vector_data.small_delta_dist_y - vector_data.delta_dist_y;
	hit_point->wall_height = ((int)(SCREEN_HEIGHT / hit_point->distance));
	hit_point->wall_max_height_pixel
		= hit_point->wall_height / 2 + SCREEN_HEIGHT / 2;
	if (hit_point->wall_max_height_pixel >= SCREEN_HEIGHT)
		hit_point->wall_max_height_pixel = SCREEN_HEIGHT - 1;
	hit_point->wall_min_height_pixel
		= -hit_point->wall_height / 2 + SCREEN_HEIGHT / 2;
	if (hit_point->wall_min_height_pixel < 0)
		hit_point->wall_min_height_pixel = 0;
}

/// @brief Checks if given coordinate is a hit on a wall
bool	got_a_hit(int x, int y, t_map_data map_data)
{
	if (map_data.map_tab[y][x] == '1')
		return (true);
	return (false);
}
