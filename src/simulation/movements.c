/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:54:56 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/29 17:16:42 by mde-sa--         ###   ########.fr       */
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
/// TODO: change directions depending on where one is facing
void	move_left(t_map_data *map_data, t_vector_data *vector_data)
{
	double	old_dir_x;
	double	old_dir_y;

	old_dir_x = vector_data->vector_dir_x;
	old_dir_y = vector_data->vector_dir_y;
	vector_data->vector_dir_x = vector_data->vector_dir_x * cos(-M_PI / 2)
		- vector_data->vector_dir_y * sin(-M_PI / 2);
	vector_data->vector_dir_y = old_dir_x * sin(-M_PI / 2)
		+ vector_data->vector_dir_y * cos(-M_PI / 2);
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
	vector_data->vector_dir_x = old_dir_x;
	vector_data->vector_dir_y = old_dir_y;
	printf("Position after movement:\n");
	print_vector_data(vector_data);
}

/// @brief Walks 1 MOVE_SPEED right
/// TODO: change directions depending on where one is facing
void	move_right(t_map_data *map_data, t_vector_data *vector_data)
{
	double	old_dir_x;
	double	old_dir_y;

	old_dir_x = vector_data->vector_dir_x;
	old_dir_y = vector_data->vector_dir_y;
	vector_data->vector_dir_x = vector_data->vector_dir_x * cos(M_PI / 2)
		- vector_data->vector_dir_y * sin(M_PI / 2);
	vector_data->vector_dir_y = old_dir_x * sin(M_PI / 2)
		+ vector_data->vector_dir_y * cos(M_PI / 2);
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
	vector_data->vector_dir_x = old_dir_x;
	vector_data->vector_dir_y = old_dir_y;
	printf("Position after movement:\n");
	print_vector_data(vector_data);
}
