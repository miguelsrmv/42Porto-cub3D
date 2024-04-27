/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:39:16 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/27 15:47:58 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	test_map_data(t_map_data *map_data)
{
	ft_printf("File Fd:\t%i\n", map_data->file_fd);
	ft_printf("North texture:\t%s\n", map_data->north_texture);
	ft_printf("South texture:\t%s\n", map_data->south_texture);
	ft_printf("East texture:\t%s\n", map_data->east_texture);
	ft_printf("West texture:\t%s\n", map_data->west_texture);
	ft_printf("Floor:\t\t%i,%i,%i\n", map_data->floor_color[0],
		map_data->floor_color[1], map_data->floor_color[2]);
	ft_printf("Ceiling:\t%i,%i,%i\n", map_data->ceiling_color[0],
		map_data->ceiling_color[1], map_data->ceiling_color[2]);
}

void	test_tab_data(t_map_data *map_data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("Here's the tabbed data:\n\n");
	while (map_data->map_tab[y])
	{
		x = 0;
		while (map_data->map_tab[y][x])
		{
			printf("%c", map_data->map_tab[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n\nPlayer starting position is:\n");
	printf("X: %i\n", map_data->start_pos[1]);
	printf("Y: %i\n", map_data->start_pos[0]);
	printf("Orientation: %c\n\n", map_data->cardinal_direction);
}

void	print_ray_data(t_target *target_array, int array_index)
{
	printf("Ray %04i hit at position (%i, %i): \
	wall drawn from min %i to max %i, colour %i.\n",
		array_index,
		(int)target_array[array_index].x_position,
		(int)target_array[array_index].y_position,
		target_array[array_index].wall_min_height_pixel,
		target_array[array_index].wall_max_height_pixel,
		target_array[array_index].wall_facing_direction);
}

void	print_vector_data(t_vector_data *vector)
{
	printf("Player position (%i, %i) looking at (%f, %f)\n",
		vector->pos_x,
		vector->pos_y,
		vector->vector_dir_x,
		vector->vector_dir_y);
	printf("Vector PosX: %f, Vector PosY: %i\n",
		(vector->pos_x + vector->ray_dir_x * MOVE_SPEED),
		(int)(vector->pos_y));
}
