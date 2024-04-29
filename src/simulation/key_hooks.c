/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:21:44 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/29 09:55:12 by mde-sa--         ###   ########.fr       */
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
