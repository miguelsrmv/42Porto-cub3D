/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_intersection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:19:31 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/26 19:34:51 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Gets first intersection given a ray angle
/// Fills hit_point with that data
/// TODO: Check it's working properly ???
void	get_intersection(t_map_data map_data,
			t_vector_data vector_data, int ray_angle, t_target *hit_point)
{
	bool		hit_flag;

	hit_flag = check_first_intersection(map_data, vector_data, ray_angle, hit_point);
	while (!hit_flag) //Falta a condicao se for impossivel X/Y hit
	{
		if (vector_data.small_delta_dist_x < vector_data.small_delta_dist_y)
		{
			vector_data.small_delta_dist_x += vector_data.delta_dist_x;
			hit_point->x_position += vector_data.step_x;
			check_wall_side_vertical(vector_data.step_x, hit_point);
		}
		else
		{
			vector_data.small_delta_dist_y += vector_data.delta_dist_y;
			hit_point->y_position += vector_data.step_y;
			check_wall_side_horizontal(vector_data.step_y, hit_point);
		}
		if (hit_point->y_position == 51)
			printf("YAY!");
		if (got_a_hit(hit_point->x_position, hit_point->y_position, map_data))
			hit_flag = true;
	}
	calc_wall_distance_and_height(vector_data, hit_point);
}

/// @brief Checks if given coordinate is a hit on a wall
bool	got_a_hit(double x_position, double y_position, t_map_data map_data)
{
	int		x_coordinate;
	int		y_coordinate;

	x_coordinate = (int)(x_position / TILE_SIZE);
	y_coordinate = (int)(y_position / TILE_SIZE);
	if (map_data.map_tab[y_coordinate][x_coordinate] == '1')
		return (true);
	return (false);
}
