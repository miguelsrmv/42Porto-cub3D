/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:21:44 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/13 10:23:21 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Triggers event flag on keypress
int	key_press_hook(int keycode, t_cube *cube)
{
	if (keycode == ESCAPE)
	{
		cube->escape = true;
		return (0);
	}
	if (keycode == KEY_W)
		cube->move_foward = true;
	else if (keycode == KEY_S)
		cube->move_back = true;
	else if (keycode == KEY_A)
		cube->move_left = true;
	else if (keycode == KEY_D)
		cube->move_right = true;
	else if (keycode == KEY_LEFT_ARROW)
		cube->look_left = true;
	else if (keycode == KEY_RIGHT_ARROW)
		cube->look_right = true;
	return (0);
}

/// @brief Untriggers event flag on keyrelease
int	key_release_hook(int keycode, t_cube *cube)
{
	if (keycode == KEY_W)
		cube->move_foward = false;
	else if (keycode == KEY_S)
		cube->move_back = false;
	else if (keycode == KEY_A)
		cube->move_left = false;
	else if (keycode == KEY_D)
		cube->move_right = false;
	else if (keycode == KEY_LEFT_ARROW)
		cube->look_left = false;
	else if (keycode == KEY_RIGHT_ARROW)
		cube->look_right = false;
	return (0);
}

/// @brief Gets user input and triggers respective event
void	execute_movement(t_cube *cube)
{
	if (cube->escape)
	{
		mlx_loop_end(cube->mlx);
		return ;
	}
	if (cube->move_foward)
		move(cube->map_data, cube->vector_data, FOWARD);
	if (cube->move_back)
		move(cube->map_data, cube->vector_data, BACKWARDS);
	if (cube->move_left)
		move(cube->map_data, cube->vector_data, LEFT);
	if (cube->move_right)
		move(cube->map_data, cube->vector_data, RIGHT);
	if (cube->look_left)
		turn_left(cube->vector_data);
	if (cube->look_right)
		turn_right(cube->vector_data);
}

/// @brief Function for setting up key_hooks
void	setup_keyhooks(t_cube *cube)
{
	mlx_hook(cube->mlx_window, 2, 1L << 0, key_press_hook, cube);
	mlx_hook(cube->mlx_window, 3, 1L << 1, key_release_hook, cube);
}

/// @brief Function for setting up minimize and escape buttons
/// TODO: set maximize (requires changing SCREEN WIDTH AND HEIGHT)
void	setup_buttonhooks(t_cube *cube)
{
	mlx_hook(cube->mlx_window, 17, 1L << 17, mlx_loop_end, cube->mlx);
}
