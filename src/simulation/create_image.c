/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:49:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/26 13:58:51 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Creates image by casting rays throughout all FOV
/// TODO: Separate this into create floor/ceiling, create walls, etc
void	create_image(t_map_data map_data, t_vector_data *vector_data,
				t_mlx_img *img)
{
	t_target	target_array[FOV + 1];
	int			i;
	int			fov_angle;

	// Draw floor and ceiling "canvas"
	i = 0;
	while (i <= FOV)
	{
		fov_angle = i - (FOV / 2);
		target_array[i] = cast_ray(map_data, vector_data, fov_angle);
		i++;
	}
	(void)img;
	(void)target_array;
	// Draw using target_array
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

/// @brief Gets intersection with first wall
void	get_intersection(t_map_data map_data,
			t_vector_data vector_data, int ray_angle, t_target *hit_point)
{
	bool		hit_flag;

	hit_flag = check_first_intersection(map_data, vector_data, ray_angle, hit_point);
	while (!hit_flag) //Falta a condicao se for impossivel X/Y hit
	{
		continue ;
	}
}

/// @brief Checks if the very first wall gets intersected or not
bool	check_first_intersection(t_map_data map_data,
			t_vector_data vector_data, int ray_angle, t_target *hit_point)
{
	double	horizontal_hit;
	double	vertical_hit;
	
	(void)map_data;
	(void)vector_data;
	(void)ray_angle;
	(void)horizontal_hit;
	(void)vertical_hit;
	(void)hit_point;
	return (false);
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
