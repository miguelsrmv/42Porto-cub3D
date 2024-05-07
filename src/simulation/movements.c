/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:54:56 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/07 18:11:46 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Walks 1 MOVE_SPEED / TILE_SIZE to the desired direction
void	move(t_map_data *map_data, t_vector_data *vector_data, enum e_Movement movement)
{
	t_vector_data	vector_rotated;

	vector_rotated = *vector_data;
	rotate_vector_data(&vector_rotated, movement);
	update_position(map_data, vector_data, &vector_rotated);
}

/// @brief Gets rotated vector
void	rotate_vector_data(t_vector_data *vector_rotated, enum e_Movement movement)
{
	if (movement == BACKWARDS)
	{
		vector_rotated->vector_dir_x = -vector_rotated->vector_dir_x;
		vector_rotated->vector_dir_y = -vector_rotated->vector_dir_y;
	}
	else if (movement == LEFT)
	{
		vector_rotated->vector_dir_x = vector_rotated->vector_dir_y;
		vector_rotated->vector_dir_y = -vector_rotated->vector_dir_x;
	}
	else if (movement == RIGHT)
	{
		vector_rotated->vector_dir_x = -vector_rotated->vector_dir_y;
		vector_rotated->vector_dir_y = vector_rotated->vector_dir_x;
	}
}

/// @brief Updates player position if no collision is detected
void	update_position(t_map_data *map_data, t_vector_data *vector_data,
			t_vector_data *vector_rotated)
{
	if (player_collides(map_data, vector_rotated))
	{
		printf("Can't move in that direction!\n");
		return ;
	}
	vector_data->pos_x += vector_rotated->vector_dir_x * MOVE_SPEED / TILE_SIZE;
	vector_data->pos_y += vector_rotated->vector_dir_x * MOVE_SPEED / TILE_SIZE;
	vector_data->map_x = (int)vector_data->pos_x;
	vector_data->map_y = (int)vector_data->pos_y;
}

/// @brief Checks if there's an obstacle within a +- 45º field of
/// (movement_vector_x, movement_vector_y), returning if player collides or not
bool	player_collides(t_map_data *map_data, t_vector_data *vector_rotated)
{
	t_target	target_array[SCREEN_WIDTH];
	int			i;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		target_array[i] = cast_ray(*map_data, vector_rotated, i);
		if (target_array[i].distance < WALL_OFFSET)
			return (true);
		i++;
	}
	return (false);
}
