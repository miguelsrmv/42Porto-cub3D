/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:54:56 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/29 09:56:38 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	printf("Pos X was added %f and Pos Y was added %f",
		vector_data->vector_dir_x * MOVE_SPEED,
		vector_data->vector_dir_y * MOVE_SPEED);
}

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
	printf("Pos X was subtracted %f and Pos Y was subtracted %f",
		vector_data->vector_dir_x * MOVE_SPEED,
		vector_data->vector_dir_y * MOVE_SPEED);
}
