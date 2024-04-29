/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:54:56 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/29 18:38:42 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Walks 1 MOVE_SPEED foward
void	move_foward(t_map_data *map_data, t_vector_data *vector_data)
{
	if ((map_data->map_tab
			[(int)vector_data->pos_y]
			[(int)(vector_data->pos_x
				+ vector_data->vector_dir_x * MOVE_SPEED)]) != '1')
		vector_data->pos_x
			+= round(vector_data->vector_dir_x * MOVE_SPEED);
	if ((map_data->map_tab
			[(int)(vector_data->pos_y
				+ vector_data->vector_dir_y * MOVE_SPEED)]
		[(int)(vector_data->pos_x)]) != '1')
		vector_data->pos_y
			+= round(vector_data->vector_dir_y * MOVE_SPEED);
	printf("Position after movement:\n");
	print_vector_data(vector_data);
}

/// @brief Walks 1 MOVE_SPEED backwads
void	move_backwards(t_map_data *map_data, t_vector_data *vector_data)
{
	if ((map_data->map_tab
			[(int)vector_data->pos_y]
			[(int)(vector_data->pos_x
				- vector_data->vector_dir_x * MOVE_SPEED)]) != '1')
		vector_data->pos_x
			-= round(vector_data->vector_dir_x * MOVE_SPEED);
	if ((map_data->map_tab
			[(int)(vector_data->pos_y - vector_data->vector_dir_y * MOVE_SPEED)]
		[(int)(vector_data->pos_x)]) != '1')
		vector_data->pos_y -= round(vector_data->vector_dir_y * MOVE_SPEED);
	printf("Position after movement:\n");
	print_vector_data(vector_data);
}

/// @brief Walks 1 MOVE_SPEED left
void	move_left(t_map_data *map_data, t_vector_data *vector_data)
{
	double	perpendicular_x;
	double	perpendicular_y;

	perpendicular_x = vector_data->vector_dir_y;
	perpendicular_y = -vector_data->vector_dir_x;
	if (map_data->map_tab
		[(int)(vector_data->pos_y + perpendicular_y * MOVE_SPEED)]
		[(int)(vector_data->pos_x)] != '1')
		vector_data->pos_y += round(perpendicular_y * MOVE_SPEED);
	if (map_data->map_tab
		[(int)(vector_data->pos_y)]
		[(int)(vector_data->pos_x + perpendicular_x * MOVE_SPEED)] != '1')
		vector_data->pos_x += round(perpendicular_x * MOVE_SPEED);
	printf("Position after movement:\n");
	print_vector_data(vector_data);
}

/// @brief Walks 1 MOVE_SPEED right
void	move_right(t_map_data *map_data, t_vector_data *vector_data)
{
	double	perpendicular_x;
	double	perpendicular_y;

	perpendicular_x = vector_data->vector_dir_y;
	perpendicular_y = -vector_data->vector_dir_x;
	if (map_data->map_tab
		[(int)(vector_data->pos_y - perpendicular_y * MOVE_SPEED)]
		[(int)(vector_data->pos_x)] != '1')
		vector_data->pos_y -= round(perpendicular_y * MOVE_SPEED);
	if (map_data->map_tab
		[(int)(vector_data->pos_y)]
		[(int)(vector_data->pos_x - perpendicular_x * MOVE_SPEED)] != '1')
		vector_data->pos_x -= round(perpendicular_x * MOVE_SPEED);
	printf("Position after movement:\n");
	print_vector_data(vector_data);
}
