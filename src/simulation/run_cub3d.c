/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:54:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/09 12:31:29 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief 		Runs cub3d simulation. Starts mlx shenanigans.
void	run_cub3d(t_cube	*cube)
{
	initialize_mlx(cube);
	load_textures(cube, cube->map_data);
	mlx_loop_hook(cube->mlx, render_image, cube);
	setup_keyhooks(cube);
	setup_buttonhooks(cube);
	mlx_loop(cube->mlx);
	clean_mlx(cube->mlx, cube->mlx_window, (cube->image.img));
}

/// @brief		Initializes the mlx process.
void	initialize_mlx(t_cube *cube)
{
	void			*mlx;
	void			*mlx_window;
	t_mlx_img		image;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT,
			cube->map_data->window_title);
	image.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	cube->mlx = mlx;
	cube->mlx_window = mlx_window;
	cube->image = image;
}

/// @brief Loads textures into memory
void	load_textures(t_cube *cube, t_map_data *map_data)
{
	int	load_count;

	load_count = 0;
	while (load_count < 3)
	{
		map_data->texture[load_count].img
			= mlx_xpm_file_to_image(cube->mlx,
				map_data->textr_path[load_count],
				&map_data->texture[load_count].width,
				&map_data->texture[load_count].height);
		if (map_data->texture[load_count].img == NULL)
		{
			while (load_count--)
				mlx_destroy_image(cube->mlx, map_data->texture[load_count].img);
			mlx_destroy_display(cube->mlx);
			free(cube->mlx);
			exit_cub3(map_data, LOAD_TEXTURE_MSG);
		}
		load_count++;
	}
}

/// @brief Renders image
int	render_image(t_cube *cube)
{
	create_image(*(cube->map_data), cube->vector_data, &(cube->image));
	mlx_put_image_to_window(cube->mlx, cube->mlx_window, cube->image.img, 0, 0);
	return (0);
}
