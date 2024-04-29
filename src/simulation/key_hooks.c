/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:21:44 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/29 10:02:39 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Gets user input and triggers respective event
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
		move_left(cube->map_data, cube->vector_data);
	else if (keycode == KEY_D)
		move_right(cube->map_data, cube->vector_data);
	else if (keycode == KEY_LEFT_ARROW)
		turn_left(cube->vector_data);
	else if (keycode == KEY_RIGHT_ARROW)
		turn_right(cube->vector_data);
	return (0);
}
