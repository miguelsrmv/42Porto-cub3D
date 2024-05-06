/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:21:44 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/06 20:28:48 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Gets user input and triggers respective event
/// TODO: REMOVE SPACE/ENTER/BACKSPACE functions AND #defines on cub3d.h
int	key_hook(int keycode, t_cube *cube)
{
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
	else if (keycode == SPACE)
		print_vector_data(cube->vector_data);
	else if (keycode == ENTER)
		print_current_perspective(cube->map_data, cube->vector_data);
	else if (keycode == BACKSPACE)
		print_current_map(cube->map_data, cube->vector_data);
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
