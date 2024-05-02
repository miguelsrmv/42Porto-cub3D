/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:53:00 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/02 12:38:41 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Checks if there's an obstacle within a +- 45º field of
/// (movement_vector_x, movement_vector_y), returning if player collides or not
bool	player_collides(t_map_data *map_data, t_vector_data *vector_data,
	double movement_vector_x, double movement_vector_y)
{
	double	target_position_x;
	double	target_position_y;

	return (false);
	target_position_x = vector_data->pos_x + movement_vector_x;
	target_position_y = vector_data->pos_x + movement_vector_y;
	if (map_data->map_tab
		[(int)target_position_y][(int)target_position_x] == '1')
		return (true);
	return (false);
}
