/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:21:44 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/27 15:50:08 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_cube *cube)
{
	printf("\n*********************\n\n");
	printf("Current position:\n");
	print_vector_data(cube->vector_data);
	printf("\n");
	if (keycode == KEY_W)
		move_foward(cube->map_data, cube->vector_data);
	else if (keycode == KEY_S)
		move_backwards(cube->map_data, cube->vector_data);
	else if (keycode == KEY_A)
		turn_left(cube->vector_data);
	else if (keycode == KEY_D)
		turn_right(cube->vector_data);
	return (0);
}

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

void	turn_left(t_vector_data *vector_data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vector_data->vector_dir_x;
	old_plane_x = vector_data->camera_plane_x;
	vector_data->vector_dir_x
		= vector_data->vector_dir_x * cos(-ROTATE_SPEED)
		- vector_data->vector_dir_y * sin(-ROTATE_SPEED);
	vector_data->vector_dir_y
		= old_dir_x * sin(-ROTATE_SPEED)
		+ vector_data->vector_dir_y * cos(-ROTATE_SPEED);
	vector_data->camera_plane_x
		= vector_data->camera_plane_x * cos(-ROTATE_SPEED)
		- vector_data->camera_plane_y * sin(-ROTATE_SPEED);
	vector_data->camera_plane_y
		= old_plane_x * sin(-ROTATE_SPEED)
		+ vector_data->camera_plane_y * cos(-ROTATE_SPEED);
}

void	turn_right(t_vector_data *vector_data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vector_data->vector_dir_x;
	old_plane_x = vector_data->camera_plane_x;
	vector_data->vector_dir_x
		= vector_data->vector_dir_x * cos(ROTATE_SPEED)
		- vector_data->vector_dir_y * sin(ROTATE_SPEED);
	vector_data->vector_dir_y
		= old_dir_x * sin(ROTATE_SPEED)
		+ vector_data->vector_dir_y * cos(ROTATE_SPEED);
	vector_data->camera_plane_x
		= vector_data->camera_plane_x * cos(ROTATE_SPEED)
		- vector_data->camera_plane_y * sin(ROTATE_SPEED);
	vector_data->camera_plane_y
		= old_plane_x * sin(ROTATE_SPEED)
		+ vector_data->camera_plane_y * cos(ROTATE_SPEED);
}
