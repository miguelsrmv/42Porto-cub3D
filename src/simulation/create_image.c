/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:49:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/27 15:40:24 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Creates image
void	create_image(t_map_data map_data, t_vector_data *vector_data,
				t_mlx_img *img)
{
	draw_background(map_data, img);
	draw_obstacles(map_data, vector_data, img);
}

/// @brief Draws ceiling and floor
void	draw_background(t_map_data map_data, t_mlx_img *img)
{
	int	width;
	int	height;
	int	colour;

	height = 0;
	colour = convert_rgb_to_int(map_data.ceiling_color);
	while (height < SCREEN_HEIGHT / 2)
	{
		width = 0;
		while (width < SCREEN_WIDTH)
			my_pixel_put(img, width++, height, colour);
		height++;
	}
	colour = convert_rgb_to_int(map_data.floor_color);
	while (height < SCREEN_HEIGHT)
	{
		width = 0;
		while (width < SCREEN_WIDTH)
			my_pixel_put(img, width++, height, colour);
		height++;
	}
}

/// @brief Gets the obstacles from each ray
/// and then sends the array to be put on image
void	draw_obstacles(t_map_data map_data, t_vector_data *vector_data,
				t_mlx_img *img)
{
	t_target	target_array[SCREEN_WIDTH];
	int			i;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		target_array[i] = cast_ray(map_data, vector_data, i);
		i++;
	}
	put_walls_on_image(target_array, img);
}

/// @brief Casts ray for each angle (player_angle + fov_angle)
t_target	cast_ray(t_map_data map_data, t_vector_data *vector_data,
				int ray_number)
{
	t_target	hit_point;

	compute_vector_data(vector_data, ray_number);
	get_intersection(map_data, *vector_data, &hit_point);
	return (hit_point);
}

/// @brief Draws the walls
/// TODO: Replace colour by textures!
void	put_walls_on_image(t_target *target_array, t_mlx_img *img)
{
	int	array_index;
	int	pixels_height;
	int	colour;

	array_index = 0;
	while (array_index < SCREEN_WIDTH)
	{
		pixels_height = target_array[array_index].wall_min_height_pixel;
		colour = temp_colour(target_array[array_index].wall_facing_direction);
		while (pixels_height <= target_array[array_index].wall_max_height_pixel)
		{
			my_pixel_put(img, array_index, pixels_height, colour);
			pixels_height++;
		}
		array_index++;
	}
}
