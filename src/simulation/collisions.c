/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:53:00 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/06 20:28:11 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Checks if there's an obstacle within a +- 45º field of
/// (movement_vector_x, movement_vector_y), returning if player collides or not
bool	player_collides(t_map_data *map_data, t_vector_data *vector_data,
	double movement_vector_x, double movement_vector_y)
{
	return (false);
	if (frontal_collision(map_data, vector_data,
			movement_vector_x, movement_vector_y)
		|| minus_45_collision(map_data, vector_data,
			movement_vector_x, movement_vector_y)
		|| plus_45_collision(map_data, vector_data,
			movement_vector_x, movement_vector_y))
		return (true);
	return (false);
}

bool	frontal_collision(t_map_data *map_data, t_vector_data *vector_data,
	double movement_vector_x, double movement_vector_y)
{
	double	final_movement_vector_x;
	double	final_movement_vector_y;

	final_movement_vector_x = vector_data->pos_x
		+ movement_vector_x;
	final_movement_vector_y = vector_data->pos_y
		+ movement_vector_y;
	printf("Checking vector in front (%i, %i)\n",
		(int)final_movement_vector_x,
		(int)final_movement_vector_y);
	if (map_data->map_tab
		[(int)final_movement_vector_y]
		[(int)final_movement_vector_x] == '1')
		return (true);
	return (false);
}

bool	minus_45_collision(t_map_data *map_data, t_vector_data *vector_data,
	double movement_vector_x, double movement_vector_y)
{
	double	final_movement_vector_x;
	double	final_movement_vector_y;
	double	theta;

	theta = M_PI / 4.0;
	final_movement_vector_x = vector_data->pos_x
		+ movement_vector_x * cos(theta)
		- movement_vector_y * sin(theta);
	final_movement_vector_y = vector_data->pos_y
		+ movement_vector_x * sin(theta)
		+ movement_vector_y * cos(theta);
	printf("Checking vector to the right (%i, %i)\n",
		(int)final_movement_vector_x,
		(int)final_movement_vector_y);
	if (map_data->map_tab
		[(int)final_movement_vector_y]
		[(int)final_movement_vector_x] == '1')
		return (true);
	return (false);
}

bool	plus_45_collision(t_map_data *map_data, t_vector_data *vector_data,
	double movement_vector_x, double movement_vector_y)
{
	double	final_movement_vector_x;
	double	final_movement_vector_y;
	double	theta;

	theta = -M_PI / 4.0;
	final_movement_vector_x = vector_data->pos_x
		+ movement_vector_x * cos(theta)
		- movement_vector_y * sin(theta);
	final_movement_vector_y = vector_data->pos_y
		+ movement_vector_x * sin(theta)
		+ movement_vector_y * cos(theta);
	printf("Checking vector to the left (%i, %i)\n",
		(int)final_movement_vector_x,
		(int)final_movement_vector_y);
	if (map_data->map_tab
		[(int)final_movement_vector_y]
		[(int)final_movement_vector_x] == '1')
		return (true);
	return (false);
}
