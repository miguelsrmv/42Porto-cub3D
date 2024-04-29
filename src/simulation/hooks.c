/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:21:44 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/29 18:41:57 by mde-sa--         ###   ########.fr       */
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
	else if (keycode == ESCAPE)
		mlx_loop_end(cube->mlx);
	return (0);
}

/// @brief Function for setting up key_hooks
void	setup_keyhooks(t_cube *cube)
{
	mlx_hook(cube->mlx_window, 2, 1L << 0, key_hook, cube);
}

/// @brief Function for setting up minimize and escape buttons
/// TODO: set maximize (requires changing SCREEN WIDTH AND HEIGHT)
void	setup_buttonhooks(t_cube *cube)
{
	mlx_hook(cube->mlx_window, 17, 1L << 17, mlx_loop_end, cube->mlx);
}
