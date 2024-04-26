/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:05:49 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/26 23:05:19 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_wall_side_horizontal(int step, t_target *hit_point)
{
	if (step == 1)
		hit_point->wall_facing_direction = NORTH;
	else if (step == -1)
		hit_point->wall_facing_direction = SOUTH;
}

void	check_wall_side_vertical(int step, t_target *hit_point)
{
	if (step == 1)
		hit_point->wall_facing_direction = WEST;
	else if (step == -1)
		hit_point->wall_facing_direction = EAST;
}

void	calc_wall_distance_and_height(t_vector_data vector_data, t_target *hit_point)
{
	if (hit_point->wall_facing_direction == WEST || hit_point->wall_facing_direction == EAST)
		hit_point->distance = vector_data.small_delta_dist_x - vector_data.delta_dist_x;
	else
		hit_point->distance = vector_data.small_delta_dist_y - vector_data.delta_dist_y;
/* 	if (hit_point->distance == 0)
		hit_point->wall_height = INT_MAX;
	else */
	hit_point->wall_height = (int)(SCREEN_HEIGHT / hit_point->distance);
	hit_point->wall_max_height_pixel = hit_point->wall_height / 2 + SCREEN_HEIGHT / 2;
	if (hit_point->wall_max_height_pixel >= SCREEN_HEIGHT)
		hit_point->wall_max_height_pixel = SCREEN_HEIGHT - 1;
	hit_point->wall_min_height_pixel = -hit_point->wall_height / 2 + SCREEN_HEIGHT / 2;
	if (hit_point->wall_min_height_pixel < 0)
		hit_point->wall_min_height_pixel = 0;
}
