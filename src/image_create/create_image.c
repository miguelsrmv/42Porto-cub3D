/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:49:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/17 11:11:53 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Creates image by casting rays throughout all FOV
void	create_image(t_map_data map_data, t_vector_data *vector_data,
			t_mlx_img *img)
{
	int	fov_angle;

	fov_angle = -FOV / 2;
	while (fov_angle <= (+FOV / 2))
	{
		cast_ray(map_data, vector_data, img, fov_angle);
		fov_angle++;
	}
	return ;
}

/// @brief Casts ray for each angle (player_angle + fov_angle)
void	cast_ray(t_map_data map_data, t_vector_data *vector_data,
			t_mlx_img *img, int fov_angle)
{
	double	x_distance;
	double	y_distance;

	calculate_deltas(vector_data, fov_angle);
	x_distance = get_horizontal_intersection(map_data, *vector_data, fov_angle);
	y_distance = get_vertical_intersection(map_data, *vector_data, fov_angle);
	(void)x_distance;
	(void)y_distance;
	(void)img;
}

/// @brief Gets horizontal intersection
double	get_horizontal_intersection(t_map_data map_data,
			t_vector_data vector_data, int ray_angle)
{
	float	x_step;
	float	y_step;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(ray_angle);
	(void)map_data;
	(void)vector_data;
	(void)ray_angle;
	(void)y_step;
	(void)x_step;
	return (0);
}
/// @brief Gets vertical intersection
double	get_vertical_intersection(t_map_data map_data,
			t_vector_data vector_data, int ray_angle)
{
	(void)map_data;
	(void)vector_data;
	(void)ray_angle;
	return (0);
}
