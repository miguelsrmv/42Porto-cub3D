/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:54:56 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/06 22:40:41 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Walks 1 MOVE_SPEED foward
void	move_foward(t_map_data *map_data, t_vector_data *vector_data)
{
	double	foward_vector_x;
	double	foward_vector_y;

	foward_vector_x = vector_data->vector_dir_x * MOVE_SPEED / TILE_SIZE;
	foward_vector_y = vector_data->vector_dir_y * MOVE_SPEED / TILE_SIZE;
	if (player_collides(map_data, vector_data,
			foward_vector_x, foward_vector_y))
	{
		printf("Can't move foward!\n");
		return ;
	}
	vector_data->pos_x += foward_vector_x;
	vector_data->pos_y += foward_vector_y;
	update_position(vector_data);
}

/// @brief Walks 1 MOVE_SPEED backwads
void	move_backwards(t_map_data *map_data, t_vector_data *vector_data)
{
	double	backwards_vector_x;
	double	backwards_vector_y;

	backwards_vector_x = -vector_data->vector_dir_x * MOVE_SPEED / TILE_SIZE;
	backwards_vector_y = -vector_data->vector_dir_y * MOVE_SPEED / TILE_SIZE;
	if (player_collides(map_data, vector_data,
			backwards_vector_x, backwards_vector_y))
	{
		printf("Can't move backwards!\n");
		return ;
	}
	vector_data->pos_x += backwards_vector_x;
	vector_data->pos_y += backwards_vector_y;
	update_position(vector_data);
}

/// @brief Walks 1 MOVE_SPEED left
void	move_left(t_map_data *map_data, t_vector_data *vector_data)
{
	double	leftwards_vector_x;
	double	leftwards_vector_y;

	leftwards_vector_x = -vector_data->vector_dir_x * MOVE_SPEED / TILE_SIZE;
	leftwards_vector_y = vector_data->vector_dir_y * MOVE_SPEED / TILE_SIZE;
	if (player_collides(map_data, vector_data,
			leftwards_vector_x, leftwards_vector_y))
	{
		printf("Can't move left!\n");
		return ;
	}
	vector_data->pos_y += leftwards_vector_x;
	vector_data->pos_x += leftwards_vector_y;
	update_position(vector_data);
}

/// @brief Walks 1 MOVE_SPEED right
void	move_right(t_map_data *map_data, t_vector_data *vector_data)
{
	double	rightwards_vector_x;
	double	rightwards_vector_y;

	rightwards_vector_x = vector_data->vector_dir_x * MOVE_SPEED / TILE_SIZE;
	rightwards_vector_y = -vector_data->vector_dir_y * MOVE_SPEED / TILE_SIZE;
	if (player_collides(map_data, vector_data,
			rightwards_vector_x, rightwards_vector_y))
	{
		printf("Can't move right!\n");
		return ;
	}
	vector_data->pos_y += rightwards_vector_x;
	vector_data->pos_x += rightwards_vector_y;
	update_position(vector_data);
}

void	update_position(t_vector_data *vector_data)
{
	vector_data->map_x = (int)vector_data->pos_x;
	vector_data->map_y = (int)vector_data->pos_y;
}
