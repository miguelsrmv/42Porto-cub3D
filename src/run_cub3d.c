/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:54:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/15 19:04:55 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief 		Runs cub3d simulation
//// For now, just creates image
/// @param map 	The returned struct from check_map()
void	run_cub3d(t_map_data	*map_data)
{
	void		*mlx;
	void		*mlx_window;
	t_mlx_img	image;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	image.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	run_simulation(map_data, &image);
	//set_hooks(mlx_window, mlx);
	mlx_loop(mlx);
	clean_mlx(mlx, mlx_window, image.img);
	return ;
}
