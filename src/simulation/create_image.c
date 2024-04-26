/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:49:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/26 19:16:21 by mde-sa--         ###   ########.fr       */
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
	int height;
	int colour;

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

/// @brief Gets the obstacles from each ray and then sends the array to be put on image
void	draw_obstacles(t_map_data map_data, t_vector_data *vector_data,
				t_mlx_img *img)
{
	t_target	target_array[FOV + 1];
	int			i;
	int			fov_angle;

	i = 0;
	while (i <= FOV)
	{
		fov_angle = i - (FOV / 2);
		target_array[i] = cast_ray(map_data, vector_data, fov_angle);
		i++;
	}
	put_walls_on_image(target_array, SCREEN_WIDTH / FOV, img);
}

/// @brief Draws the walls
/// TODO: Replace colour by textures!
void	put_walls_on_image(t_target *target_array, int pixels_per_ray,
				t_mlx_img *img)
{
	int	array_index;
	int	pixels_width;
	int	pixels_height;
	int	starting_height;
	int colour;

	array_index = 0;
	while (array_index <= FOV)
	{
		pixels_width = 0;
		starting_height = (SCREEN_HEIGHT - target_array[array_index].wall_height) / 2;
		colour = temp_colour(target_array[array_index].wall_facing_direction);
		while (pixels_width <= pixels_per_ray)
		{
			pixels_height = 0;
			while (pixels_height <= target_array[array_index].wall_height)
			{
				my_pixel_put(img, (array_index * pixels_per_ray) + pixels_width,
					starting_height + pixels_height, colour);
				pixels_height++;
			}
			pixels_width++;
		}
		array_index++;
	}
}

/// @brief Casts ray for each angle (player_angle + fov_angle)
t_target	cast_ray(t_map_data map_data, t_vector_data *vector_data,
				int fov_angle)
{
	t_target	hit_point;

	calculate_deltas(vector_data, fov_angle);
	get_intersection(map_data, *vector_data, fov_angle, &hit_point);
	return(hit_point);
}
