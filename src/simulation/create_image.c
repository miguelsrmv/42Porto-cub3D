/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:49:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/10 14:22:41 by mde-sa--         ###   ########.fr       */
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
		// draw_texture_collumn
		// height = target_array[width].wall_min_height_pixel;
		while (height > target_array[width].wall_min_height_pixel)
		{
			my_pixel_put(img, width, height,
				get_texture_colour(height, width, target_array));
			height--;
		}
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


int	get_texture_colour(int width, int height, t_target *target)
{
/* 	int	pixel_offset;

	if (x < 0 || x >= texture->width)
		return (0);
	if (y < 0 || y >= texture->height)
		return (0);
	pixel_offset = y * texture->line_length + x * (texture->bits_per_pixel / 8);
	return (*(int *)(texture->addr + pixel_offset)); */
	(void)width;
	return (temp_colour(target[height].wall_facing_direction));
}
/*
/// @brief Draws the walls
/// TODO: Replace colour by textures!
void	put_walls_on_image(t_map_data map_data, t_target *target_array,
			t_mlx_img *img)
{
	int			array_index;
	t_texture	texture;
	int			scale;
	float		text_y;
	int			y;
	int			colour;

	texture
		= map_data.texture[target_array[array_index].wall_facing_direction];
	scale = texture.height / SCREEN_HEIGHT;
	text_y = 0;
	if (target_array[array_index].wall_height > SCREEN_HEIGHT)
		text_y = ((target_array[array_index].wall_height - SCREEN_HEIGHT) / 2) * scale;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		colour = get_texture_color(&texture, target_array[array_index].tile_offset,	(int)text_y % texture.height);
		my_pixel_put(img, array_index, y + target_array[array_index].tile_offset, colour);
		text_y += scale;
		y++;
	}
	}
}
 */