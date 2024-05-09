/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:13:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/09 10:14:12 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Fills map_data depending on the starting characters of line
//// Will exit if duplicate data is found
void	check_wall_texture(char **line_as_tab,
		t_map_data **map_data)
{
	char	*textr_path;

	textr_path = ft_strdup(line_as_tab[1]);
	if (!textr_path)
	{
		ft_free_tabs((void **)line_as_tab);
		exit_cub3(*map_data, MALLOC_ERROR_MSG);
	}
	if (!ft_strcmp(line_as_tab[0], "NO") && !(*map_data)->textr_path[NORTH])
		(*map_data)->textr_path[NORTH] = textr_path;
	else if (!ft_strcmp(line_as_tab[0], "SO")
		&& !(*map_data)->textr_path[SOUTH])
		(*map_data)->textr_path[SOUTH] = textr_path;
	else if (!ft_strcmp(line_as_tab[0], "WE") && !(*map_data)->textr_path[WEST])
		(*map_data)->textr_path[WEST] = textr_path;
	else if (!ft_strcmp(line_as_tab[0], "EA") && !(*map_data)->textr_path[EAST])
		(*map_data)->textr_path[EAST] = textr_path;
	else
	{
		ft_free_tabs((void **)line_as_tab);
		free(textr_path);
		exit_cub3(*map_data, REPEATED_ERROR_MSG);
	}
	ft_free_tabs((void **)line_as_tab);
}

/// @brief Checks if textures exist, are .xpm, are readable
//// Will exit in case they're a dir too!
void	check_texture_files(t_map_data **map_data)
{
	int		file_fd;
	int		i;
	char	*textr_path;
	char	*buffer[1];

	i = -1;
	while (++i < 4)
	{
		textr_path = (*map_data)->textr_path[i];
		if (ft_checkextension(textr_path, ".xpm"))
			exit_cub3(*map_data, TEXTURE_WRONG_FORMAT_MSG);
		file_fd = open(textr_path, O_RDONLY);
		if (file_fd == -1)
			exit_cub3(*map_data, TEXTURE_ERROR_MSG);
		if (read(file_fd, buffer, 0) == -1 && errno == EISDIR)
		{
			close(file_fd);
			exit_cub3(*map_data, TEXTURE_ERROR_MSG);
		}
		close(file_fd);
		check_text_path_validity(map_data, textr_path);
	}
}

/// @brief Checks if the provided .xpm file is valid
void	check_text_path_validity(t_map_data **map_data, char *file_path)
{
	void	*mlx;
	void	*img;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, file_path, &img_width, &img_height);
	if (img == NULL)
	{
		mlx_destroy_display(mlx);
		free (mlx);
		exit_cub3(*map_data, TEXTURE_WRONG_FORMAT_MSG);
	}
	else
	{
		mlx_destroy_image(mlx, img);
		mlx_destroy_display(mlx);
		free(mlx);
	}
}
