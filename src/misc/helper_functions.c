/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:39:16 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/09 10:13:28 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	test_map_data(t_map_data *map_data)
{
	ft_printf("File Fd:\t%i\n", map_data->file_fd);
	ft_printf("North texture:\t%s\n", map_data->textr_path[NORTH]);
	ft_printf("South texture:\t%s\n", map_data->textr_path[SOUTH]);
	ft_printf("East texture:\t%s\n", map_data->textr_path[EAST]);
	ft_printf("West texture:\t%s\n", map_data->textr_path[WEST]);
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

/// @brief Temporary function just to test wall sides
/// 255 is Blue
/// 65280 is Green
/// 1671168 is Red
/// 16777215 is White
int	temp_colour(t_CardinalPoint direction)
{
	if (direction == NORTH)
		return (255);
	else if (direction == SOUTH)
		return (16711680);
	else if (direction == WEST)
		return (65280);
	else
		return (16777215);
}

/* void	print_ray_data(t_target *target_array, int array_index)
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
	printf("\n*********************\n\n");
	printf("Current position:\n");
	printf("Player position (%f, %f) looking at (%f, %f)\n",
		vector->pos_x,
		vector->pos_y,
		vector->vector_dir_x,
		vector->vector_dir_y);
	printf("\n");
}

void	print_current_perspective(t_map_data *map, t_vector_data *vector)
{
	t_target	target_array[SCREEN_WIDTH];
	int			i;

	printf("\n*********************\n\n");
	printf("Current perspective:\n");
	i = 0;
	while (i < SCREEN_WIDTH)
	{
		target_array[i] = cast_ray(*map, vector, i);
		if (i % 40 == 0)
			printf("Ray number %i hit a target on position (%i, %i)\n",
				i,
				(int)target_array[i].x_position,
				(int)target_array[i].y_position);
		i++;
	}
	return ;
}

void	print_current_map(t_map_data *map_data, t_vector_data *vector)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("\n*********************\n\n");
	printf("Current map:\n\n");
	while (map_data->map_tab[y])
	{
		x = 0;
		while (map_data->map_tab[y][x])
		{
			if (x == (int)(vector->pos_x - 0.5)
				&& y == (int)(vector->pos_y + 0.5))
				printf("X");
			else
				printf("%c", map_data->map_tab[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n\n");
} */