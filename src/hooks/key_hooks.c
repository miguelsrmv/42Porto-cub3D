/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:21:44 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/27 11:55:46 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_cube *cube)
{
	if (keycode == KEY_W)
		my_pixel_put(&cube->image, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
	else if (keycode == KEY_S)
		my_pixel_put(&cube->image, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1000);
	else if (keycode == KEY_A)
		my_pixel_put(&cube->image, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 10000);
	else if (keycode == KEY_D)
		my_pixel_put(&cube->image, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 100000);
	return (0);
}
