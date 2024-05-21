/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:49:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/20 14:32:54 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Creates image
/// From left to right, first draws floor, then texture, then ceiling
void	create_image(t_map_data map_data, t_vector_data *vector_data,
				t_mlx_img *img)
{
	t_target	*target_array;
	int			height;
	int			width;

	target_array = get_obstacles(map_data, vector_data);
	width = 0;
	while (width < SCREEN_WIDTH)
	{
		height = SCREEN_HEIGHT;
		while (height > target_array[width].wall_max_height_pixel)
			my_pixel_put(img, width, height--,
				convert_rgb_to_int(map_data.floor_color));
		draw_texture_collumn(target_array, width, map_data, img);
		height = target_array[width].wall_min_height_pixel;
		while (height)
			my_pixel_put(img, width, height--,
				convert_rgb_to_int(map_data.ceiling_color));
		width++;
	}
	free(target_array);
}

/// @brief Gets the obstacles from each ray
/// and then sends the array to be put on image
t_target	*get_obstacles(t_map_data map_data, t_vector_data *vector_data)
{
	t_target	*target_array;
	int			i;

	target_array = (t_target *)malloc(sizeof(t_target) * SCREEN_WIDTH);
	if (!target_array)
		exit_cub3(&map_data, MALLOC_ERROR_MSG);
	i = 0;
	while (i < SCREEN_WIDTH)
	{
		target_array[i] = cast_ray(map_data, vector_data, i);
		i++;
	}
	vector_data->front_distance = target_array[SCREEN_WIDTH / 2].distance;
	return (target_array);
}

/// @brief Casts ray for each angle
t_target	cast_ray(t_map_data map_data, t_vector_data *vector_data,
				int ray_number)
{
	t_target	hit_point;

	compute_vector_data(vector_data, ray_number);
	get_intersection(map_data, *vector_data, &hit_point);
	return (hit_point);
}
