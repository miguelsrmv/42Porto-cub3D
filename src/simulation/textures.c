/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:31:35 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/12 16:25:32 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Gets colour from texture at pixel (width, height)
int	get_texture_colour(t_texture *texture, double width, int height)
{
	int	pixel_offset;

	if (width < 0 || width >= texture->width)
		return (0);
	if (height < 0 || height >= texture->height)
		return (0);
	pixel_offset = height
		* texture->line_length + (width * (texture->bits_per_pixel / 8));
	return (*(int *)(texture->addr + pixel_offset));
}

/// @brief Draws the walls
void	draw_texture_collumn(t_target *target_array, int width,
			t_map_data map_data, t_mlx_img *img)
{
	double		scale;
	t_texture	texture;
	float		text_y;
	int			y;

	texture = map_data.texture[target_array[width].wall_facing_direction];
	scale = (double)texture.height / (double)target_array[width].wall_height;
	text_y = 0;
	if (target_array[width].wall_height > SCREEN_HEIGHT)
		text_y = ((target_array[width].wall_height - SCREEN_HEIGHT) / 2)
			* scale;
	y = 0;
	while (y < target_array[width].wall_height)
	{
		my_pixel_put(img, width, y + target_array[width].wall_min_height_pixel,
			get_texture_colour(&texture, target_array[width].texture_x_coord,
				(int)text_y % texture.height));
		text_y += scale;
		y++;
	}
}
