/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:54:56 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/13 19:01:58 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Walks 1 MOVE_SPEED / TILE_SIZE to the desired direction
void	move(t_map_data *map_data, t_vector_data *vector_data,
			t_movement movement)
{
	double	x_movement;
	double	y_movement;
	double	x_offset;
	double	y_offset;

	set_move_values(vector_data, movement, &x_movement, &y_movement);
	set_offset_values(x_movement, y_movement, &x_offset, &y_offset);
	if (map_data->map_tab[(int)vector_data->pos_y]
		[(int)(vector_data->pos_x + x_movement + x_offset)] != '1')
	{
		vector_data->pos_x += x_movement;
		vector_data->map_x = (int)vector_data->pos_x;
	}
	if (map_data->map_tab[(int)(vector_data->pos_y + y_movement + y_offset)]
		[(int)vector_data->pos_x] != '1')
	{
		vector_data->pos_y += y_movement;
		vector_data->map_y = (int)vector_data->pos_y;
	}
}

/// @brief Sets movement values
void	set_move_values(t_vector_data *vector_data, t_movement movement,
		double *x_movement, double *y_movement)
{
	if (movement == FOWARD)
	{
		*x_movement = vector_data->vector_dir_x;
		*y_movement = vector_data->vector_dir_y;
	}
	else if (movement == BACKWARDS)
	{
		*x_movement = -vector_data->vector_dir_x;
		*y_movement = -vector_data->vector_dir_y;
	}
	else if (movement == LEFT)
	{
		*x_movement = vector_data->vector_dir_y * FRONT_TO_SIDE_RATIO;
		*y_movement = -vector_data->vector_dir_x * FRONT_TO_SIDE_RATIO;
	}
	else if (movement == RIGHT)
	{
		*x_movement = -vector_data->vector_dir_y * FRONT_TO_SIDE_RATIO;
		*y_movement = vector_data->vector_dir_x * FRONT_TO_SIDE_RATIO;
	}
	*x_movement *= MOVE_SPEED / TILE_SIZE;
	*y_movement *= MOVE_SPEED / TILE_SIZE;
}

/// @brief Sets offset values to avoid collision
void	set_offset_values(double x_movement, double y_movement,
	double *x_offset, double *y_offset)
{
	if (x_movement < 0)
		*x_offset = -WALL_OFFSET;
	else
		*x_offset = WALL_OFFSET;
	if (y_movement < 0)
		*y_offset = -WALL_OFFSET;
	else
		*y_offset = WALL_OFFSET;
}
