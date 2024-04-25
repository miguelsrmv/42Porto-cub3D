/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:49:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/25 15:55:35 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Creates image by casting rays throughout all FOV
t_target	*create_image(t_map_data map_data, t_vector_data *vector_data)
{
	t_target	target_array[SCREEN_WIDTH];
	int			i;
	int			fov_angle;

	i = 0;
	while (i <= FOV)
	{
		fov_angle = i - (FOV / 2);
		target_array[i] = cast_ray(map_data, vector_data, fov_angle);
		i++;
	}
	return (target_array);
}

/// @brief Casts ray for each angle (player_angle + fov_angle)
t_target	cast_ray(t_map_data map_data, t_vector_data *vector_data, int fov_angle)
{
	t_target	target;

	calculate_deltas(vector_data, fov_angle);
	get_intersection(map_data, *vector_data, fov_angle, &target);
}

/// @brief Gets horizontal intersection
void	get_intersection(t_map_data map_data,
			t_vector_data vector_data, int ray_angle, t_target *target)
{
	bool	x_hit_flag;
	bool	y_hit_flag;
	double	x_target;
	double	y_target;

	x_hit_flag = false;
	y_hit_flag = false;
	check_quick_intersection(map_data, vector_data, )
	while (true) //Falta a condicao se for impossivel X/Y hit
	{
		if (!x_hit_flag)
		if (!y_hit_flag)
		
	}
	(void)ray_angle;
	return (0);
}

void	check_quick_intersection(t_map_data map_data,
			t_vector_data vector_data, int ray_angle, t_target *target)
{
	if (got_a_hit(vector_data.pos_x + (vector_data.step_x
		* vector_data.small_delta_dist_x), vector_data.pos_y, map_data))
	{
		x_target = vector_data.pos_x + (vector_data.step_x
		* vector_data.small_delta_dist_x);
		x_hit_flag = true;
	}
	if (got_a_hit(vector_data.pos_y + (vector_data.step_y
		* vector_data.small_delta_dist_y), vector_data.pos_x, map_data))
	{
		y_target = vector_data.pos_y + (vector_data.step_y
		* vector_data.small_delta_dist_y);
		y_hit_flag = true;
	}
}

bool	got_a_hit(double x_position, double y_position, t_map_data map_data)
{
	int		x_coordinate;
	int		y_coordinate;

	x_coordinate = (int)(x_position / TILE_SIZE);
	y_coordinate = (int)(y_position / TILE_SIZE);
	if (map_data.map_tab[y_coordinate][x_coordinate] == '1')
		return (true);
	return (true);
}
